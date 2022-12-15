import argparse
from http_module import method
TOKEN = ""
H = 1
W = 1
sim_data = []

get_method = lambda url : method("GET", url, token=TOKEN)
post_method = lambda url, data : method("POST", url, data=data, token=TOKEN)
put_method = lambda url, data : method("PUT", url, data=data, token=TOKEN)

###API###
def api_start(prob, token):
    ret = method("POST", '/start', {"problem" : prob}, token, True)
    return ret.get('auth_key', "")

#현재 날짜 예약 요청
def api_new_requests():
    #return method("GET", '/new_requests', token = TOKEN).get('reservations_info', [])
    return get_method('/new_requests').get('reservations_info', [])

#예약 요청에 대한 승낙/거절
def api_reply(data):
    #return method("PUT", '/reply', data = {"replies" : data}, token = TOKEN)
    return put_method('/reply', {"replies" : data})

#오늘 체크인하는 손님들에게 객실 번호를 배정
def api_simulate():

    res = put_method('/simulate', {"room_assign":sim_data})
    print(res)

#점수
def api_score():
    return method("GET", '/score', token = TOKEN)





###functions###
def get_response_due(request_date, checkin_date):
    return min(request_date + 14, checkin_date - 1)

def get_room_number(row, col):
    return row * 1000 + col

#비어있는 방 찾기
def find_room(amount, checkin, checkout, hotel):
    for date in range(checkin, checkout):
        for row in range(1, H+1):
            for col in range(1, W + 1):
                chk = 0
                for a in range(amount):
                    if col + a <= W:
                        if hotel[date][row][col + a] != 0:
                            chk = 1
                            break
                    else:
                        chk = 1
                        break
                if chk == 0:
                    return row, col
    
    return -1, -1

#체크인
def today_checkin(checkin, checkout, row, col, amount, hotel):
    for d in range(checkin, checkout):
        for c in range(col, col + amount):
            hotel[d][row][c] = 1


def solve(args):
    global TOKEN, H, W
    TOKEN = api_start(args.problem, args.token)
    if args.problem == 1:
        H = 3
        W = 20
        MAX_DATE = 200
        MAX_ROOM = 10
    else:
        H = 10
        W = 200
        MAX_DATE = 1000
        MAX_ROOM = 50
    
    #일자마다 이어져있는 호텔 객실을 표시하는 배열
    hotel = [[[0 for _ in range(W + 1)] for _ in range(H + 1)] for _ in range(MAX_DATE + 1)]

    #체크인,체크아웃 손님
    #checkin_list = [[] for _ in range(MAX_DATE + 1)]
    #checkout_list = [[] for _ in range(MAX_DATE + 1)]

    #방 마다 응답 대기 목록
    waiting = [[] for _ in range(MAX_ROOM + 1)]
    
    today = 1
    while today <= MAX_DATE:
        #print('-----------', today, '----------------')
        new_requests = api_new_requests()
        print(new_requests)
        #예약 요청 받아 대기 목록에 추가
        for e in new_requests:
            id = e['id']
            amount = e['amount']
            checkin_date = e['check_in_date']
            checkout_date = e['check_out_date']
            due_date = get_response_due(today, checkin_date)
            waiting[amount].append({'id' : id, 'due_date' : due_date, 'checkin_date' : checkin_date, 'checkout_date' : checkout_date, 'period' : checkout_date - checkin_date})
        
        reply_data = []
        sim_data.clear()
        tmp = []
        #승낙/거절
        r = MAX_ROOM
        while r > 0:
            #기간이 짧은 순으로 정렬
            sorted_waiting = sorted(waiting[r], key = lambda x : x['period'])
            for e in sorted_waiting:
                if e['due_date'] >= today: #기한이 아직 안 지난 경우
                    row, col = find_room(r, e['checkin_date'], e['checkout_date'], hotel)
                    if row != -1: #체크인 성공
                        room_num = get_room_number(row, col)
                        reply_data.append({"id" : e['id'], "reply" : "accepted"})
                        num1 = e['id']
                        num2 = get_room_number(row, col)
                        sim_data.append({"id":num1, "room_number":num2})
                        today_checkin(e['checkin_date'], e['checkout_date'], row, col, r, hotel)        
            r-=1

        tmp.append({"id":num1, "room_number":num2})

        print(sim_data)
        print(tmp)
        api_reply(reply_data)
        api_simulate()
        #print("reply data : ", reply_data)
        #객실 번호 배정(simulate)
        #print("simulate data : ", simulate_data)
        
        today+=1

    #점수 출력
    api_simulate([])
    print(api_score())

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--problem", type=int, default = 1)
    parser.add_argument("--token", type=str, required=True)
    args = parser.parse_args()

    solve(args)