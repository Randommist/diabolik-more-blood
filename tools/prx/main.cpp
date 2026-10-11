#include <fstream>
#include <vector>
#include <iostream>
#include "Core/ELF/PrxDecrypter.h"
int main(int argc,char **argv) {
 if(argc!=3) return 1;
 std::ifstream in(argv[1],std::ios::binary);
 std::vector<u8> b((std::istreambuf_iterator<char>(in)),{}), out(b.size());
 if(b.size()<0x150) return 2;
 int n=pspDecryptPRX(b.data(),out.data(),b.size());
 if(n<0 || n>(int)out.size()){std::cerr<<"decrypt failed "<<n<<"\n";return 3;}
 std::ofstream dst(argv[2],std::ios::binary);dst.write((char*)out.data(),n);
 std::cout<<"decrypted "<<n<<" bytes\n";
}
