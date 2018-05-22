#include <windows.h>
// #pragma comment(linker, "/subsystem:\"windows\" /entry:\"wmainCRTStartup\"")

void addEntry (int& argc, char** argv) {
  int i;
  for (i = 0; i != argc; i++) if (0 == strcmp(argv[i], "-repl")) break;
  if (i != argc) {
    int j;
    for (j = i; j != argc - 1; j++) argv[j] = argv[j + 1];
    argv[j] = nullptr;
    argc--;
    return;
  }

  char filename[MAX_PATH];
  GetModuleFileNameA(nullptr, filename, MAX_PATH);

  char* pos = strrchr(filename, '\\');
  size_t length = pos - filename;
  char index[MAX_PATH];
  strncpy_s(index, filename, length);
  strcat_s(index, "\\index.js");

  argc++;
  argv[argc - 1] = index;
}

// src/node_main.cc
// int wmain (int argc, wchar_t *wargv[]) {
//   // ...
//   addEntry(argc, argv);
//   return node::Start(argc, argv);
// }
