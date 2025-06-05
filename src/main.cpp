#include <appdef.h>
#include <cstddef>
#include <cstdio>
#include <sdk/os/debug.h>

APP_NAME("Your Cool App Name")
APP_AUTHOR("me")
APP_DESCRIPTION("A very cool app!")
APP_VERSION("1.0.0")

int main(int argc, char **argv, char **envp) {
  std::printf("Arguments:\n");
  for (std::size_t i = 0; i < static_cast<std::size_t>(argc); i++)
    std::printf(" - %zu: %s\n", i, argv[i]);

  std::printf("Environment:\n");
  for (auto ptr = envp; *ptr != 0; ptr++)
    std::printf("%s\n", *ptr);

  std::fflush(stdout);
  Debug_WaitKey();
}