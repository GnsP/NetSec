import random
import numpy

def strtomat(text):
    textMatrix  = [ 0 for x in range(len(text))]
    for i in range(len(text)):
        textMatrix[i] = ord(text[i]) - ord('A')

    return numpy.matrix(textMatrix)

def mattostr(Matrix):
    str = ''
    for i in range(len(Matrix)):
        str = str + chr(Matrix[i] + ord('A'))
    return str

def Encrypt(KeyMatrix, tempString):
    return mattostr(KeyMatrix * strtomat(tempString).T)
    

if __name__ == "__main__":
    choice = int(raw_input("Use as Encrypter or Decrypter (1/0): "))
    if(choice == 1):
        Plaintext = raw_input("Enter Plaintext: ")
        Block = int(raw_input("Enter Block Size: "))
        #Plaintext = "TGEEMNELNNTDROEOAAHDOETCSHAEIRLM"
        #Block = 8
    
        n = len(Plaintext)

        # Filling bogus characters if the length doesn't matches
        temp = n%Block
        if(temp != 0):
            for i in range(Block - temp):
                Plaintext = Plaintext + 'X'

        print "\nPlainText: %s\n" % str(Plaintext)
    
        Key = list(range(Block))
        print "Mapping: "
        print "Inital: %s" % str(Key)
        random.shuffle(Key)
        #Key = [3, 0, 5, 1, 6, 2, 7, 4]
        print "Key:    %s\n\n" % str(Key)
        print "Key Matrix Used: "
        KeyMatrix = numpy.zeros((Block, Block))
        for i in range(Block):
            KeyMatrix[i][Key[i]] = 1
        print KeyMatrix

        for i in range(len(Plaintext)/Block):
            tempString = Plaintext[Block * i : Block * (i+1)]
            #print tempString
            print tempString + str(" : "),
            print Encrypt(KeyMatrix, tempString)

    else:
        Ciphertext = raw_input("Enter Ciphertext: ")
        Block = int(raw_input("Enter Block Size: "))
        if(len(Ciphertext) % Block != 0):
            print "Length of Ciphertext should be multiple of Block"

        else:
            Key = raw_input("Enter the Key Mapping (0 indexed): ")
            Key  = map(int, Key.split())

            print "\nPlainText: %s\n" % str(Ciphertext)

            print "Mapping: "
            print "Inital: %s" % str(list(range(len(Key))))
            print "Key:    %s\n\n" % str(Key)
            print "Key Matrix Used: "
            KeyMatrix = numpy.zeros((Block, Block))
            for i in range(Block):
                KeyMatrix[i][Key[i]] = 1
            print KeyMatrix

            for i in range(len(Ciphertext)/Block):
                tempString = Ciphertext[Block * i : Block * (i+1)]
                print tempString + str(" : "),
                print Encrypt(KeyMatrix.T, tempString)
