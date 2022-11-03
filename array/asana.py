##This is removeOneDigit() function, it takes two strings as input
def removeOneDigit(s,t):
    ##Take a variable, total_count, it's initial value is 0
    total_count=0 
    ##Start a for loop, to traverse s string from left to right
    for i in range(len(s)):
        ##If current character is in range from '0' to '9' then,
        if '0'<=s[i]<='9':
            ##Create a string from s, excluding current character
            temp=s[:i]+s[i+1:]
            ##If this new string is less than t then increment total_count by 1
            if temp<t:
                total_count+=1 
    ##Start a for loop, to traverse t string from left to right
    for i in range(len(t)):
        ##If current character is in range from '0' to '9' then,
        if '0'<=t[i]<='9':
            ##Create a string from t, excluding current character
            temp=t[:i]+t[i+1:]
            ##If this new string is greater than s then increment total_count by 1
            if s<temp:
                total_count+=1 
    ##Now,return the value stored in total_count variable 
    return total_count 

print(removeOneDigit("ab12c", "1zz456"))
