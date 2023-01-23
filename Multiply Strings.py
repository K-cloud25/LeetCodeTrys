class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        conv = {"0":0,"1":1,"2":2,"3":3,"4":4,"5":5,"6":6,"7":7,"8":8,"9":9}
        num1 = [*num1][::-1]
        num2 = [*num2][::-1]
        num,temp=1,0
        for i in num1:
            temp = temp + num*conv[i]
            num=num*10
        num1 = temp
        num,temp=1,0
        for i in num2:
            temp = temp + num*conv[i]
            num=num*10
        num2 = temp
        return str(num1 * num2)
