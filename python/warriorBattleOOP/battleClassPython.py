import random
import numpy as np

class Warrior:
    def __init__(self, name, health, attackMax, blockMax):
        self.name = name
        self.health = health
        self.attackMax = attackMax
        self.blockMax = blockMax
        self.damage = 0
        # TODO: self.stats = {} for tabulate

    def attack(self):
        randomValue = random.randrange(1, 5, 1)
        attackAmount = round( (randomValue / self.attackMax) * 100)
        return attackAmount

    def block(self):
        randomValue = random.randrange(1, 5, 1)
        blockAmount = round ( (randomValue / self.blockMax) * 100)
        return blockAmount

class Battle:
    def __init__(self, warriorA, warriorB):
        self.warriorA  = warriorA
        self.warriorB = warriorB
        self.warriorAAttkAmt = 0
        self.warriorBBlockAmt = 0
        self.damage2warriorB = 0
        self.count = 0
        self.temp = None
        # TODO: self.stats = {} for tabulate

    def swapWarriors(self):
        self.temp = self.warriorA
        self.warriorA = self.warriorB
        self.warriorB = self.temp

    def startFight(self):
        while True:
            # each warrior take turns attacking until a warriors health < 0
            if self.getAttackResult() == "Game Over":
                print(f"Game Over")
                break

            # swap which warrior attacks which after each round
            self.swapWarriors()
            
            # increment round count and break if battle >30 rounds
            self.count += 1
            print(f"Current round # = {self.count}")
            if self.count > 30:
                break

    def getAttackResult(self):
        # identify warriors
        print(f"Warrior A = {self.warriorA.name}")
        print(f"Warrior B = {self.warriorB.name}")

        # Get random attack & block amounts
        self.warriorAAttkAmt = self.warriorA.attack()
        self.warriorBBlockAmt = self.warriorB.block()
        self.damage2warriorB = np.ceil(self.warriorAAttkAmt - self.warriorBBlockAmt)

        # log to console
        print(f"damage2warriorB = {self.damage2warriorB}")
        print(f"warriorAAttkAmt = {self.warriorAAttkAmt}")
        print(f"warriorBBlockAmt = {self.warriorBBlockAmt}")

        # calculate damage
        print(f"Warrior B health before strike = {self.warriorB.health}")
        if self.damage2warriorB <= 0:
            self.damage2warriorB = -(self.damage2warriorB)
        self.warriorB.health = (self.warriorB.health - self.damage2warriorB)
        print(f"Warrior B health after strike {self.warriorB.health}")

        # Once health < 0 end game by passing back Game Over
        if self.warriorB.health <= 0:
            print(f"{self.warriorB.name} has died and {self.warriorA.name} is victorious!")
            print(f"Round Count = {self.count}")
            return "Game Over"
        else:
            print(f"Fighting Again with warriorB health = {self.warriorB.health}")
            return "Fight Again"

if __name__ == "__main__":
    warrior1 = Warrior("Kevin", 100, 15, 15)
    warrior2 = Warrior("Joe", 100, 25, 25)

    battle1 = Battle(warrior1, warrior2)
    battle1.startFight()
       
