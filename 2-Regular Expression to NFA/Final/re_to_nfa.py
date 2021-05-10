transition_table = [ [0]*3 for _ in range(20) ]

re = input("Enter the regular expression : ")
re += " "

i = 0
j = 1
while(i<len(re)):
    if re[i] == 'a':
        try:
            if re[i+1] != '|' and re[i+1] !='*':
                transition_table[j][0] = j+1
                j += 1
            elif re[i+1] == '|' and re[i+2] =='b':
                transition_table[j][2]=((j+1)*10)+(j+3)
                j+=1
                transition_table[j][0]=j+1
                j+=1
                transition_table[j][2]=j+3
                j+=1
                transition_table[j][1]=j+1
                j+=1
                transition_table[j][2]=j+1
                j+=1
                i=i+2
            elif re[i+1]=='*':
                transition_table[j][2]=((j+1)*10)+(j+3)
                j+=1
                transition_table[j][0]=j+1
                j+=1
                transition_table[j][2]=((j+1)*10)+(j-1)
                j+=1
        except:
            transition_table[j][0] = j+1

    elif re[i] == 'b':
        try:
            if re[i+1] != '|' and re[i+1] !='*':
                transition_table[j][1] = j+1
                j += 1
            elif re[i+1]=='|' and re[i+2]=='a':
                transition_table[j][2]=((j+1)*10)+(j+3)
                j+=1
                transition_table[j][1]=j+1
                j+=1
                transition_table[j][2]=j+3
                j+=1
                transition_table[j][0]=j+1
                j+=1
                transition_table[j][2]=j+1
                j+=1
                i=i+2
            elif re[i+1]=='*':
                transition_table[j][2]=((j+1)*10)+(j+3)
                j+=1
                transition_table[j][1]=j+1
                j+=1
                transition_table[j][2]=((j+1)*10)+(j-1)
                j+=1
        except:
            transition_table[j][1] = j+1
        
    elif re[i]=='e' and re[i+1]!='|'and re[i+1]!='*':
        transition_table[j][2]=j+1
        j+=1

    elif re[i]==')' and re[i+1]=='*':

        transition_table[0][2]=((j+1)*10)+1
        transition_table[j][2]=((j+1)*10)+1
        j+=1

    i +=1

print ("Transition function:")
for i in range(j):
    if(transition_table[i][0]!=0):
        print("q[{0},a]-->{1}".format(i,transition_table[i][0]))
    if(transition_table[i][1]!=0):
        print("q[{0},b]-->{1}".format(i,transition_table[i][1]))
    if(transition_table[i][2]!=0):
        if(transition_table[i][2]<10):
            print("q[{0},e]-->{1}".format(i,transition_table[i][2]))
        else:
            print("q[{0},e]-->{1} & {2}".format(i,int(transition_table[i][2]/10),transition_table[i][2]%10))
