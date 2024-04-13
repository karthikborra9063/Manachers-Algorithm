def manachers(str):
    def convert_string(s):
        result = '@#'
        for char in s:
            result += char + '#'
        result+="$"
        return result
    converted_str = convert_string(str)
    l = len(converted_str)
    P = [0] * l
    C = 1
    R = 1

    for i in range(1,l-1):
        mirror = 2 * C - i
        if i < R:
            P[i] = min(R - i, P[mirror])
        while(converted_str[i + P[i] + 1] == converted_str[i - P[i] - 1]):
            P[i] += 1
        if i + P[i] > R:
            C = i
            R = i + P[i]
    max_len = 0
    center_ind = 0
    for i in range(l):
        if P[i] > max_len:
            max_len = P[i]
            center_ind = i

    start = (center_ind - max_len) // 2
    print(f"Given string is: {str}")
    print(f"Length of longest palindromic sub string is {max_len}")
    print(f"Longest Palindromic sub string is {str[start:start + max_len]}")

file=open("py_input.txt","r")
str=file.read()
manachers(str)
