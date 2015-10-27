import numpy

def MulInverse(n, radix):
    for i in range(1, radix):
        if(((i * n) % 26) == 1):
            return i

def ModInv(matrix):
    C = numpy.zeros(matrix.shape)
    nrows, ncols = C.shape
    for row in xrange(nrows):
        for col in xrange(ncols):
            minor = matrix[numpy.array(range(row)+range(row+1,nrows))[:,numpy.newaxis],
                           numpy.array(range(col)+range(col+1,ncols))]
            C[row, col] = (-1)**(row+col) * int(round(numpy.linalg.det(minor)))
    C = C.T
    D = int(round(numpy.linalg.det(matrix)))
    if (D < 0) :
        D = D * -1
        C = C * -1
    invD = MulInverse(D, 26)
    C = C * invD
    return C % 26



if __name__ == "__main__":
    Plaintext = raw_input("Enter plaintext: ")
    Key = raw_input("Enter key: ")
    n = len(Plaintext)
    PlaintextMatrix  = [ 0 for x in range(n)]
    KeyMatrix = [[0 for x in range(n)] for x in range(n)]
    while(len(Key) < n*n):
        Key = Key + Key

    for i in range(n):
        PlaintextMatrix[i] = ord(Plaintext[i]) - ord('A')
    for i in range(n*n):
        KeyMatrix[i/n][i%n] = ord(Key[i]) - ord('A')

    
    PlaintextMatrix = numpy.matrix(PlaintextMatrix)
    KeyMatrix = numpy.matrix(KeyMatrix)
    CipherMatrix = KeyMatrix * PlaintextMatrix.T
    
    print "PlaintextMatrix: "
    print PlaintextMatrix.T
    print "KeyMatrix: "
    print KeyMatrix
    print "CipherMatrix: "
    CipherMatrix = CipherMatrix % 26
    print CipherMatrix
    print "CipherText: ",
    for i in range(len(CipherMatrix)):
        print chr(CipherMatrix[i] + ord('A')),
    print 
    invKeyMatrix = ModInv(KeyMatrix)
    print "InverseKeyMatrix: "
    print invKeyMatrix
    DecryptedMatrix = invKeyMatrix * CipherMatrix
    DecryptedMatrix = DecryptedMatrix % 26
    print "Decrpyted Matrix"
    print DecryptedMatrix
    for i in range(len(DecryptedMatrix)):
        print chr(DecryptedMatrix[i] + ord('A')),
    print 