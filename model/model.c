// http://eli.thegreenplace.net/2012/01/03/understanding-the-x64-code-models
int global_arr[100] = {2, 3};
static int static_arr[100] = {9, 7};
int global_arr_big[50000] = {5, 6};
static int static_arr_big[50000] = {10, 20};

int global_func(int param)
{
  return param * 10;
}

int main(int argc, const char* argv[])
{
  int t = global_func(argc);
  t += global_arr[7];
  t += static_arr[7];
  t += global_arr_big[7];
  t += static_arr_big[7];
  return t;
}
