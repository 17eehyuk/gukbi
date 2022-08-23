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
        return Monster.damage_table[attacker][defender] * power



HP = 1000
game_speed = 0.2        # 값이 작을수록 빠름

while True:
    attack = Monster.attack_type[random.randint(0, len(Monster.attack_type)-1)]
    defense = Monster.defense_type[random.randint(0, len(Monster.defense_type)-1)]
    damage = Monster.clac_damage(attack,defense, random.randint(50,70))
    HP = round(HP - damage)
    if HP < 0:
        HP = 0
    print(f'공격 : {attack}, 수비 : {defense}, 데미지 : {damage}, 남은체력 : {HP}')
    
    if HP == 0:
        break
    time.sleep(game_speed)
