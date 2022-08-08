# # 동전교환 프로그램
# import math
# money = int(input('투입금액 : '))

# money500 = math.trunc(money/500)
# money = money%500

# money100 = math.trunc(money/100)
# money = money%100

# money50 = math.trunc(money/50)
# money = money%50

# money10 = math.trunc(money/10)

# print(f'''
# 500원짜리 {money500}개,
# 100원짜리 {money100}개,
# 50원짜리 {money50}개,
# 10원짜리 {money10}개
# ''')


# # 윤년계산
# year = int(input('년도입력 : '))

# if(year%4 == 0):
#     if(year%100 == 0):
#         if(year%400 == 0):
#             print('윤년')
#         else:
#             print('평년')
#     else:
#         print('윤년')
# else:
#     print('평년')


# #########                  #
#                     #                     #
#                 #                         #
#             #                             #
#         #       #                       #
#     #               #                   #
# #                       #               #

#         #                               #
#         #                               #
#         #                               #
#         #############
#         #                               #
#         #                               #
#         #                               #
#         #############


# # 구구단
# a = range(2,10)
# b = range(1,10)
# for i in a:
#     print(f'{i}단')
#     for j in b:
#         mul = i*j
#         print(f'''{i} x {j} = {mul}''')


# # 아스키코드 출력
# for i in range(128):
#     print(chr(i))


#  문자열 거꾸로 출력
in_str = input('입력 : ')
out_str = ''
for i in range(len(in_str)):
    out_str += in_str[len(in_str)-i-1]
print(f'''출력 : {out_str}''')
