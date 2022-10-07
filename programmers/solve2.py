import argparse

from http_json2 import http_method
TOKEN = ""
BASE_URL = "https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod"
SKILL_AVG = 40000
SKILL_MAX = 100000
SKILL_MIN = 1000

get_method = lambda url : http_method("GET", BASE_URL, url, token = TOKEN)
post_method = lambda url, data : http_method("POST", BASE_URL, url, data, token = TOKEN)
put_method = lambda url, data : http_method("PUT", BASE_URL, url, data, token = TOKEN)

def api_start(prob, init_token):
    res = http_method("POST", BASE_URL, "/start", data ={"problem" : prob}, token = init_token, init = True)
    return res.get("auth_key", "")

def api_waiting_line():
    return get_method('/waiting_line').get('waiting_line',[])

def api_game_result():
    return get_method('/game_result').get('game_result', [])

def api_user_info():
    return get_method('/user_info').get('user_info', [])

def api_match(data):
    return put_method('/match', {'pairs' : data})

def api_change_grade(data):
    return put_method('/change_grade', {'commands' : data})

def api_score():
    return get_method('/score')

#####functions######

def get_skill_gap(taken):
    return (40 - taken) * 99000 / 35

def get_prob(skill_win, skill_lose, real_gap):
    #이긴사람 기준에서 승률
    win_prob = skill_win / (2 * skill_win - real_gap)
    #진 사람 기준에서 승률
    lose_prob = (skill_lose + real_gap) / (2 * skill_lose + real_gap)
    
    if 2 * skill_win > real_gap:
        ret = (win_prob + lose_prob) / 2
    else:
        ret = lose_prob

    return ret


def solve(args):
    global TOKEN
    TOKEN = api_start(args.problem, args.init_token)
    print(TOKEN)
    if args.problem == 1:
        num_users = 30
    elif args.problem == 2:
        num_users = 900

    #모든 사람 평균으로 맞추기
    skills = {}
    for id in range(1, num_users + 1):
        skills[id] = SKILL_AVG
    
    #595턴까지
    for now in range(595):
        #게임 결과를 가지고 수정
        game_result = api_game_result()
        for rst in game_result:
            win = rst['win']
            lose = rst['lose']
            taken = rst['taken']
            expected_gap = abs(skills[win] - skills[lose])
            real_gap = get_skill_gap(taken)
            prob = get_prob(skills[win], skills[lose], real_gap)
            value = prob * (expected_gap - real_gap) / 2
            if value >= 0:
                skills[win] = max(SKILL_MIN, skills[win] - value)
                skills[lose] = min(SKILL_MAX, skills[lose] + value)
            else:
                skills[win] = min(SKILL_MAX, skills[win] + value)
                skills[lose] = max(SKILL_MIN, skills[lose] - value)

        #대기열을 보고 새로운 매칭
        waiting_line = api_waiting_line()
        waiting_line = sorted(waiting_line, key = lambda w : skills[w['id']], reverse = True)
        idx = 0
        match_data = []
        while idx + 1 < len(waiting_line):
            wait_id1 = waiting_line[idx]['id']
            wait_id2 = waiting_line[idx + 1]['id']
            wait_time = now - waiting_line[idx]['from']
            if skills[wait_id1] - skills[wait_id2] < 100:
                match_data.append([wait_id1, wait_id2])
                idx += 1
            idx += 1
        api_match(match_data)
    skills = sorted(skills.items(), key = lambda x : x[1], reverse=True)
    grade_data = []
    for e in skills:
        grade_data.append({'id' : e[0], 'grade' : e[1]})
    api_change_grade(grade_data)
    api_match([])
    return api_score()




if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--problem', type = int, default = 1)
    parser.add_argument('--init-token', type = str, required = True)
    args = parser.parse_args()

    print(solve(args))