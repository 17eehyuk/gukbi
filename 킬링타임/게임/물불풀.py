import random
import time
import pandas as pd

class Monster:
    attack_type = ['물', '불', '풀','노말']
    defense_type = ['물', '불', '풀']
    damage_rate = [[0.5, 0.5,2,1], [2, 0.5,0.5,1], [0.5, 2,0.5,1]]
    # 데미지표[a][b]      # a : 공격타입, b : 방어타입      # 이런식으로 데미지 배율이 출력
    damage_table = pd.DataFrame(damage_rate, columns=attack_type, index=defense_type)
    
    #데미지계산
    def clac_damage(attacker : str, defender : str, power : int):

        """
        clac_damage(a,b,c) : 매개변수 3개 이용
        a : 공격
        b : 방어
        c : 데미지
        """
        return Monster.damage_table[attacker][defender] * power

game_speed = 0.2        # 값이 작을수록 빠름

# 엔트리 [방어타입, 체력]
player_A = [['물',500],['불',500],['풀',500]] 
player_B = [['물',500],['불',500],['풀',500]]

# 현재 몬스터
A_Monster = 0
B_Monster = 0


# A는 내가 조작
# B는 컴퓨터 (우선은 항상공격)
while True:
    A_attack = Monster.attack_type[random.randint(0, len(Monster.attack_type)-1)]
    A_defence = player_A[A_Monster][0]
    A_HP = player_A[A_Monster][1]
    B_attack = Monster.attack_type[random.randint(0, len(Monster.attack_type)-1)]
    B_defence = player_B[B_Monster][0]
    B_HP = player_B[B_Monster][1]
    
    print(f'플레이어A => 방어타입 : {A_defence},  남은체력 : {A_HP}')
    print(f'플레이어B => 방어타입 : {B_defence},  남은체력 : {B_HP}')

    # 데미지이기 때문에 (내공격, 상대방어, 데미지) 이런식으로 입력
    A_damage = 0
    B_damage = Monster.clac_damage(B_attack ,A_defence, random.randint(50,70))

    # 플레이어 행동
    while True:
        cmd = input('공격 0, 방어 1, 교체 2, 엔트리확인 3\n')
        if cmd == '0':
            A_damage = Monster.clac_damage(A_attack ,B_defence, random.randint(50,70))
        elif cmd == '1':
            B_damage = 0
        elif cmd == '2':
            while True:
                new_Monster = input('번호입력 0:물, 1:불, 2:풀 c:취소\n')
                if not(new_Monster == '0' or new_Monster == '1' or new_Monster == '2' or new_Monster == 'c'):
                    print('잘못된 입력')
                    continue
                elif new_Monster == 'c':
                    break
                elif new_Monster == str(A_Monster):       # 현재랑 번호랑 같은경우
                    print('같은 몬스터임')
                    continue
                else:
                    A_Monster = int(new_Monster)
                    #체력정보 변경
                    A_HP = player_A[A_Monster][1]
                break
        elif cmd == '3':
            print(player_A)
            continue
        else:
            print('잘못된 입력')
            continue
        break

    print(f'{A_damage}, {B_damage}')

    A_HP = round(A_HP - B_damage)
    B_HP = round(B_HP - A_damage)

    if A_HP < 0:
        A_HP = 0
    if B_HP < 0:
        B_HP = 0 
    player_A[A_Monster][1] = A_HP
    player_B[B_Monster][1] = B_HP


    time.sleep(game_speed)
