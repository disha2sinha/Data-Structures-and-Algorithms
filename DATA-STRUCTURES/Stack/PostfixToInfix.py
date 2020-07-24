def infix(exp_list):
    stack = []
    for i in range(len(exp_list)):
        if exp_list[i] == '+' or exp_list[i] == '-' or exp_list[i] == '/' or exp_list[i] == '*' or exp_list[i] == '^':
            operand1 = stack.pop()
            operand2 = stack.pop()
            stack.append("("+operand2+exp_list[i]+operand1+")")
        else:
            stack.append(exp_list[i])
    return stack[-1]


expression = input("Enter Postfix Expression : ")
exp_list = list(expression)
i = infix(exp_list)
print("Infix Expression : ",i)
