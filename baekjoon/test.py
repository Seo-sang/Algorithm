import math


############입출력############

# #기본적으로 문자열 입력
# input = input("값을 입력하세요: ")
# print(input)

# #정수 입력
# int_input = int(input("값을 입력하세요: "))
# print(int_input)

# #list 입력
# list_input = list(map(int, input().split()))
# print(list_input) # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

# #tuple 입력
# tuple_input = tuple(map(int, input().split()))
# print(tuple_input) # (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

# #반복문으로 입력
# loop_input = [input() for _ in range(5)]
# print(loop_input)




############수식 계산############

# a1 = 10
# a2 = 20
# a3 = a1 + a2
# print(a3)

# #나눗셈(/) 몫(//) 나머지(%)
# aa = 10
# bb = 6
# print(aa / bb)
# print(aa // bb)
# print(aa % bb)

# #우선순위
# print(5 + 7 / 3)
# print((5 + 7) / 3)


# #라이브러리
# print(math.ceil(4.5)) #올림
# print(math.floor(4.3)) #내림
# print(math.isqrt(9)) #제곱근

# #근의 공식
# a = 1
# b = 5
# c = 1
# result = (-b + math.isqrt((b * b) - (4 * a * c))) / (2 * a)
# print(result)





############함수############

# def add(a, b):
#     return a + b

# def func():
#     print("안녕하세요.")


# print(add(10, 20))

# func()