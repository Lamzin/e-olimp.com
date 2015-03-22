n = int(input())
mas = []
for lines in range(n):
    mas.append(input())
ar = [[0 for j in range(n)] for i in range(n)]
ar[0][0] = 1

for i in range(1, n):
    ar[i][0] = ar[i-1][0] if ar[i-1][0] and mas[i][0]=='.' else 0
    ar[0][i] = ar[0][i-1] if ar[0][i-1] and mas[0][i]=='.' else 0

for i in range(1,n):
    for j in range(1,n):
        ar[i][j] = (ar[i-1][j] + ar[i][j-1]) if mas[i][j]=='.' else 0
        
print(ar[n-1][n-1] if ar[n-1][n-1] else "THE GAME IS A LIE")
