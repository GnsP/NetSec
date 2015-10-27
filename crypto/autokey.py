from base import Cipher

class Autokey(Cipher):
    def __init__(self,key='FORTIFICATION'):
        self.key = [k.upper() for k in key]
        
    def encipher(self,string):
        string = self.remove_punctuation(string)
        ret = ''
        for (i,c) in enumerate(string):
            if i<len(self.key): offset = self.a2i(self.key[i])
            else: offset = self.a2i(string[i-len(self.key)])     
            ret += self.i2a(self.a2i(c)+offset)
        return ret    

    def decipher(self,string):
        string = self.remove_punctuation(string)
        ret = ''
        for (i,c) in enumerate(string):
            if i<len(self.key): offset = self.a2i(self.key[i])
            else: offset = self.a2i(ret[i-len(self.key)])             
            ret += self.i2a(self.a2i(c)-offset)
        return ret    

if __name__ == '__main__':
	ky = raw_input("key : ")
	msg = raw_input("message : ")
	ciph = Autokey(ky)
	enc = ciph.encipher(msg)
	print enc
	dec = ciph.decipher(enc)
	print dec
