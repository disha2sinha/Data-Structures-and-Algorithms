def operation(op1, op2, operator):
    if operator == "+":
        return op1+op2
    if operator == "-":
        return op1-op2
    if operator == "*":
        return op1*op2
    if operator == "/":
        return op1/op2
    if operator == "^":
        return op1^op2


def evaluate(exp_list):
    stack = []
    for i in range(len(exp_list)):
        if exp_list[i] == '+' or exp_list[i] == '-' or exp_list[i] == '/' or exp_list[i] == '*' or exp_list == '^':
            operand1 = int(stack.pop())
            operand2 = int(stack.pop())
            stack.append(operation(operand2, operand1, exp_list[i]))
        else:
            stack.append(exp_list[i])
    return stack[-1]


expression = input("Enter Postfix Expression: ")
exp_list = list(expression)
e = evaluate(exp_list)
print("Result :",e)
