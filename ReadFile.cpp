#include "ReadFile.h"
#include <iostream>
#include <string>


ReadFile::ReadFile(const char* file_name)
{
   // ReadFile* rf = new ReadFile;

   input_file.open(file_name);
   closed = false;
   _eof = false;

}

ReadFile::~ReadFile()
{
   // delete input_file;
   // delete closed;
   // delete _eof;

}

bool ReadFile::eof()
{
   return _eof;
}

void ReadFile::close()
{
   if (!closed)
   {
      input_file.close();
      closed = true;
   }
}

String* ReadFile::readLine()
{
   if (closed) return NULL;
   if (_eof) return NULL;

   string text;
   _eof = !(getline(input_file, text));

   String* str = new String((const char*) text.c_str());
   return str;
}

