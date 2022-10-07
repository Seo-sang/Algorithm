import argparse

from http_json2 import http_method

MIN_SKILL = 1000
MAX_SKILL = 100000
AVR_SKILL = 40000
STD_SKILL = 20000
D = MAX_SKILL - MIN_SKILL

BASE_URL = 'https://huqeyhi95c.execute-api.ap-northeast-2.amazonaws.com/prod'
TOKEN = ""

problem_info = {1: {"num_users" : 30, "avr_match " : 1},
                2: {"num_users" : 900, "avr_match" : 45}}



def api_start(problem, init_token):
    assert 1 <= problem <= 2
    res = http_method("POST", BASE_URL, "/start", data={'problem' : problem}, token = init_token, init = True)
    return res.get('auth_key', "")

#GET 메소드
def api_score():
    return http_method("GET", BASE_URL, "/score", token = TOKEN)

def api_waiting_line(now):
    return http_method("GET", BASE_URL, "/waiting_line", token = TOKEN).get('waiting_line', [])

def api_game_result():
    return http_method("GET", BASE_URL, "/game_result", token = TOKEN).get('game_result', [])

def api_user_info():
    return http_method("GET", BASE_URL, "/user_info", token = TOKEN).get('user_info', [])


#PUT 메소드
def api_match(data):
    return http_method("PUT", BASE_URL, "/match", {"pairs" : data}, TOKEN)

def api_change_grade(data):
    return http_method("PUT", BASE_URL, "/change_grade", {"commands" : data}, TOKEN)




#functions
def get_real_gap(real_time):
    return (real_time - 40) / 35 * 99000 #-5 ~ 5의 평균값은 0이기 때문에 무시

def get_relibaility(win, lose, real_gap):
    #win기준으로 이길 확률
    win_prob = win / (2 * win - real_gap)
    #lose기준으로 이길 확률
    lose_prob = (lose + real_gap) / (lose * 2 + real_gap)

    return (win_prob + lose_prob) / 2


def solve(args):
    global TOKEN
    TOKEN = api_start(args.problem, args.init_token)
    num_users = problem_info[args.problem]['num_users']

    skills = {}
    for id in range(1, num_users + 1):
        skills[id] = AVR_SKILL

    for now in range(595):
        #게임 결과 확인
        game_result = api_game_result()
        for rst in game_result:
            win = rst['win']
            lose = rst['lose']
            real_time = int(rst['taken'])
            estimated_gap = abs(skills[win] - skills[lose])
            real_gap = get_real_gap(real_time)
            prob = get_relibaility(skills[win], skills[lose], real_gap)
            value = prob * (estimated_gap - real_gap)
            if value >= 0:
                skills[win] = max(MIN_SKILL, skills[win] - value)
                skills[lose] = min(MAX_SKILL, skills[lose] + value)
            else:
                skills[win] = min(MAX_SKILL, skills[win] + value)
                skills[lose] = max(MIN_SKILL, skills[lose] - value)
        #점수 수정
        change_data = []
        for id in range(1, num_users + 1):
            change_data.append({"id" : id, "grade" : skills[id]})

        #대기열 확인
        waiting_line = api_waiting_line(now)
        tmp_line = {}
        for e in waiting_line:
            if now - e['from'] == 15:
                tmp_line[e['id']] = skills[e['id']]
        sorted_line = sorted(tmp_line.items(), key = lambda x : x[1], reverse=True)
        match_data = []
        i = 0
        while i + 1 < len(sorted_line):
            match_data.append([sorted_line[i][0], sorted_line[i + 1][0]])
            i += 2
        api_match(match_data)
    sorted_skills = sorted(skills.items(), key = lambda x : x[1], reverse = True)
    api_match([])

    return api_score()
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--problem", type=int, default = 1)
    parser.add_argument("--init-token", type=str, required=True)
    parser.add_argument("--match-skill", type=int, default=STD_SKILL)
    parser.add_argument("--wait-weight", type=int, default=3)
    args = parser.parse_args()

    print(solve(args))