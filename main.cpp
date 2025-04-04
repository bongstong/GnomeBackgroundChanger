#include <chrono>
#include <cstdlib>
#include <filesystem>
#include <string>
#include <thread>
#include <vector>
/*program that switches the wallpaper in GNOME DE*/

std::vector<std::string> pictures;
using namespace std::chrono_literals;

std::vector<std::string> iterate(std::vector<std::string> pictures) {

  /*iterate through directory and output all wallpapers from it*/
  int index = 0;
  namespace fs = std::filesystem;

  fs::recursive_directory_iterator it(""); // add the path here
  fs::recursive_directory_iterator end;
  for (; it != end; ++it, index++) {
    std::string path_str = it->path().string();
    pictures.push_back(path_str);
  }

  return pictures;
}

void setWp(void) {
  /*function that changes the desktop background*/
  std::vector<std::string> wps = iterate(pictures);

  for (;;) {
    for (int index = {0}; index < wps.size(); index++) {
      std::string command =
          "gsettings set org.gnome.desktop.background picture-uri-dark ";
      command = command + wps[index];
      const char *full_command = command.c_str();
      system(full_command);
      std::this_thread::sleep_until(std::chrono::system_clock::now() + 8s);
    }
    return;
  }
}

int main(void) {
  /*main function*/
  setWp();
  return EXIT_SUCCESS;
}
