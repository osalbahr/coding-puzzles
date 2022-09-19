  int main()
  {
      void (*i_am_bleeding)() = (void(*)())15;
      i_am_bleeding();
      return 0;
  }
