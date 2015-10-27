alph = "abcdefghijklmnopqrstuvwxyz"
freq = [0.082, 0.015, 0.028, 0.043, 0.127, 0.022, 0.020, 0.061, 0.070, 0.002, 0.008, 0.040, 0.024, 0.067,
		0.075, 0.018, 0.001, 0.060, 0.063, 0.091, 0.028, 0.010, 0.023, 0.001, 0.020, 0.001]

def keySize(ct):
	l = [0]
	sz = len(ct)
	for s in range(1,11):
		ct_ = ct[-s:]+ct[:-s]
		count = 0
		for i in range(sz):
			if ct[i] == ct_[i]:
				count += 1
		l.append(count)
	
	res = l.index(max(l))
	return res

def getFreqVector(ct, ksize):
	res = [[0 for j in range(26)] for i in range(ksize)]
	sz = len(ct)
	for j in range(ksize):
		for i in range(j,sz,ksize):
			res[j][alph.index(ct[i])] += 1

	for i in range(ksize):
		for j in range(26):
			res[i][j] /= sz

	return res

def dotProd(a, b):
	r = 0
	for i in range(len(a)):
		r += a[i]*b[i]
	return r

def getKeyword(freqTbl):
	key = []
	keysz = len(freqTbl)
	for k in range(keysz):
		l=[]
		for i in range(26):
			fq_ = freq[-i:]+freq[:-i]
			val = dotProd(fq_, freqTbl[k])
			l.append(val)
		keyChIndex = l.index(max(l))
		key.append(alph[keyChIndex])
	return key

if __name__ == '__main__':
	cipherText = input()
	keysz = keySize(cipherText)
	print(keysz)
	print(''.join(getKeyword(getFreqVector(cipherText, keysz))))
	


