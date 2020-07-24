def precedence(operator):
    if operator == '+' or operator == '-':
        return 1
    if operator == '*' or operator == '/':
        return 2
    if operator=='^':
        return 3

def postfix(expression):
    stack = []
    p = ''
    stack.append('(')
    exp_list.append(')')
    for i in range(0, len(exp_list)):
        if exp_list[i].isdigit() or exp_list[i].isalpha():
            p += exp_list[i]
        elif exp_list[i] == "(":
            stack.append(exp_list[i])
        elif exp_list[i] == '+' or exp_list[i] == '-' or exp_list[i] == '/' or exp_list[i] == '*'or exp_list[i]=='^':
            while True:
                if stack[len(stack)-1] == '(':
                        break
                if precedence(stack[len(stack)-1]) >= precedence(exp_list[i]):
                    item = stack.pop()
                    p += item
                else:
                    break
            stack.append(exp_list[i])
        elif exp_list[i] == ')':
            while True:
                if stack[len(stack)-1] == '(':
                    stack.pop()
                    break
                else:
                    item = stack.pop()
                    p += item
    return p


expression = input()
exp_list = list(expression)
p = postfix(exp_list)
print(p)
