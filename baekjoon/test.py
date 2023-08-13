import math

############입출력############

# #기본적으로 문자열 입력
input = input("숫자를 하나 입력하세요: ")
print("입력하신 숫자는 " + input + "입니다.")

#여러 숫자 입력
a, b, c = map(int, input().split())
print(a, b, c)

#정수 입력
int_input = int(input("값을 입력하세요: "))
print(int_input)


#list 입력
list_input = list(map(int, input().split()))
print(list_input) # [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print(list_input[0])

#tuple 입력
tuple_input = tuple(map(int, input().split()))
print(tuple_input) # (1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

#반복문으로 입력
loop_input = [input() for _ in range(5)]
print(loop_input)




###########수식 계산############

a1 = 10
a2 = 20
a3 = a1 - a2
print(a3)

# 나눗셈(/) 몫(//) 나머지(%)
aa = 10
bb = 6
print(aa / bb)
print(aa // bb)
print(aa % bb)
print(round(aa / bb, 1))

# *(곱셈)

# 우선순위
print(5 + 7 / 3)
print((5 + 7) / 3)


# 라이브러리
print(math.ceil(4.5)) #올림
print(math.floor(4.3)) #내림
print(math.isqrt(9)) #제곱근

# #근의 공식
a = 1
b = 2
c = 5
result = (-b +  math.isqrt((b * b) - (4 * a * c))) / (2 * a)





###########함수############
def 영민(a):
    print("안녕하세요.", a)


# print(add(10, 20))

영민(10)


#######베르누이 방정식#######
print("베르누이 방정식 : p + (rho * v * v) / 2 + (rho * g * h)\n\n")
v = float(input("유선 내 한 점에서의 유동 속도 v를 입력하세요 : "))
g = 9.8
h = float(input("기준면에 대한 그 점의 높이 h를 입력하세요 : "))
p = float(input("해당 점에서의 압력p를 입력하세요 : "))
rho = float(input("유체의 밀도 rho를 입력하세요 : "))

result = p + (rho * v * v) / 2 + (rho * g * h)

print("결과는 ", result, "입니다.")