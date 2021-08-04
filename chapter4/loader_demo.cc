/* Demonstrate the binary loader from ../inc/loader.cc */

#include <stdio.h>
#include <stdint.h>
#include <string>

#include "../inc/loader.h"

int
main(int argc, char *argv[])
{
  size_t i;
  Binary bin;
  Section *sec;
  Section *sec_find;
  Symbol *sym;
  std::string fname;

  sec_find = NULL;
  if(argc < 2) {
    printf("Usage: %s <binary>\n", argv[0]);
    return 1;
  }

  fname.assign(argv[1]);
  if(load_binary(fname, &bin, Binary::BIN_TYPE_AUTO) < 0) {
    return 1;
  }
  printf("loaded binary '%s' %s/%s (%u bits) entry@0x%016jx\n", 
         bin.filename.c_str(), 
         bin.type_str.c_str(), bin.arch_str.c_str(), 
         bin.bits, bin.entry);

  for(i = 0; i < bin.sections.size(); i++) {
    sec = &bin.sections[i];
    printf("  0x%016jx %-8ju %-20s %s\n", 
           sec->vma, sec->size, sec->name.c_str(), 
           sec->type == Section::SEC_TYPE_CODE ? "CODE" : "DATA");
    if(argc != 3) continue;
    if(sec->name.compare(std::string(argv[2])) == 0){
      sec_find = sec;
    }

  }

  if(bin.symbols.size() > 0) {
    printf("scanned symbol tables\n");
    for(i = 0; i < bin.symbols.size(); i++) {
      sym = &bin.symbols[i];
      printf("  %-40s 0x%016jx %s\n", 
             sym->name.c_str(), sym->addr, 
             (sym->type & Symbol::SYM_TYPE_FUNC) ? "FUNC" : "");
    }
  }
  if(sec_find != NULL) {
    printf("Section : %s size : %d\n",sec_find->name.c_str(),sec_find->size);
    for(int i=1;i <= sec_find->size;i++){
      if(i%16 == 1) {
        printf("0x%jx : ",sec_find->vma + i - 1);
      }
      printf("%02x",sec_find->bytes[i-1]);
      if(i%16 == 0) printf("\n");
      if(i%8 == 0 && i%16 != 0) printf(" ");
    }
  }
  unload_binary(&bin);

  return 0;
}