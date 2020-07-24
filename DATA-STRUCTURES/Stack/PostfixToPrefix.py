def prefix(exp_list):
    stack = []
    for i in range(len(exp_list)):
        if exp_list[i] == '+' or exp_list[i] == '-' or exp_list[i] == '/' or exp_list[i] == '*' or exp_list=='^':
            operand1 = stack.pop()
            operand2 = stack.pop()
            stack.append(exp_list[i]+operand2+operand1)
        else:
            stack.append(exp_list[i])
    return stack[-1]


expression = input()
exp_list = list(expression)
p = prefix(exp_list)
print(p)
