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


# 윤년계산
year = int(input('년도입력 : '))

if(year%4 == 0):
    if(year%100 == 0):
        if(year%400 == 0):
            print('윤년')
        else:
            print('평년')
    else:
        print('윤년')
else:
    print('평년')


#########                  #
                    #                     #
                #                         #
            #                             #
        #       #                       #
    #               #                   #
#                       #               #

        #                               #
        #                               #
        #                               #
        #############
        #                               #
        #                               #
        #                               #
        #############
