def isPal(s):
  return s == s[::-1]
S = input()
mx = 0
for i in range(len(S)):
  for j in range(i+1,len(S)+1):
    if not isPal(S[i:j]): mx = max(mx,j-i)
print(mx)
