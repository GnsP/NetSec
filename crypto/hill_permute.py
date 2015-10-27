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
    if invD != None:
        C = C * invD
        return C % 26
    else:
        print 'Inverse doesn\'t exist'



if __name__ == "__main__":
    Ciphertext = raw_input("Enter Ciphertext: ")
    Ciphertext = Ciphertext.lower()
    Block = int(raw_input("Enter Block Size: "))
    n = len(Ciphertext)

    # Filling bogus characters if the length doesn't matches
    temp = n%Block
    if(temp != 0):
        for i in range(Block - temp):
            Ciphertext = Ciphertext + 'x'
            
    CipherMatrix  = [ 0 for x in range(Block)]

    print "\nCipherText: %s\n" % str(Ciphertext)
    Key = raw_input("Enter the Key Mapping (0 indexed)")
    Key = map(int, Key.split())
    KeyMatrix = numpy.zeros((Block, Block))
    for i in range(Block):
        KeyMatrix[i][Key[i]] = 1
    plaintext = ''
    for k in range(len(Ciphertext)/Block):  
        CipherMatrix = []      
        for i in range(Block):
            CipherMatrix.append(ord(Ciphertext[Block*k+i]) - ord('a'))

        CipherMatrix = numpy.matrix(CipherMatrix)
        KeyMatrix = numpy.matrix(KeyMatrix)

        print "KeyMatrix: "
        print KeyMatrix
        
        invKeyMatrix = ModInv(KeyMatrix)
        print "InverseKeyMatrix: "
        print invKeyMatrix
        DecryptedMatrix = invKeyMatrix * CipherMatrix.T
        DecryptedMatrix = DecryptedMatrix % 26
        print "Decrpyted Matrix"
        print DecryptedMatrix
        for i in range(len(DecryptedMatrix)):
            plaintext += chr(DecryptedMatrix[i] + ord('a'))
            print chr(DecryptedMatrix[i] + ord('a')),
        print 
    print plaintext
