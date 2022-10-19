#include<iostream>
#include<stdlib.h>

using namespace std;
int installProcess();

int main(){
  int option;

    cout << "\n1. INSTALAR CONFIG ";
    cout << "\n2.  SALIR ";
    cout << "\n--> ";
    cin >> option;

    switch(option){
      case 1: installProcess();
      break;
      case 2: system("exit");
      break;
      default : system("exit");
    }
  return 0;
}

int installProcess()
  {
    //actualizar system
    system("sudo apt update");
    system("sudo parrot-upgrade");

    //instalando dependecias de Entorno
    system("sudo apt install -y build-essential git vim xcb libxcb-util0-dev libxcb-ewmh-dev libxcb-randr0-dev libxcb-icccm4-dev libxcb-keysyms1-dev libxcb-xinerama0-dev libasound2-dev libxcb-xtest0-dev libxcb-shape0-dev");

    //instalando requerimientos para la poly bar
    system("sudo apt install -y cmake cmake-data pkg-config python3-sphinx libcairo2-dev libxcb1-dev libxcb-util0-dev libxcb-randr0-dev libxcb-composite0-dev python3-xcbgen xcb-proto libxcb-image0-dev libxcb-ewmh-dev libxcb-icccm4-dev libxcb-xkb-dev libxcb-xrm-dev libxcb-cursor-dev libasound2-dev libpulse-dev libjsoncpp-dev libmpdclient-dev libuv1-dev libnl-genl-3-dev");
    
    //Dependencias de Picom
    system("sudo apt install -y meson libxext-dev libxcb1-dev libxcb-damage0-dev libxcb-xfixes0-dev libxcb-shape0-dev libxcb-render-util0-dev libxcb-render0-dev libxcb-composite0-dev libxcb-image0-dev libxcb-present-dev libxcb-xinerama0-dev libpixman-1-dev libdbus-1-dev libconfig-dev libgl1-mesa-dev libpcre2-dev libevdev-dev uthash-dev libev-dev libx11-xcb-dev libxcb-glx0-dev libpcre3 libpcre3-dev");
    
    //Instalamos paquetes adionales
    system("sudo apt install -y feh scrot scrub zsh rofi xclip bat locate neofetch wmname acpi bspwm sxhkd imagemagick ranger kitty");

    //Creando carpeta de Reposistorios
    system("mkdir ~/github");

    //Descargar Repositorios Necesarios
    system("cd ~/github");
    system("git clone --recursive https://github.com/polybar/polybar");
    system("git clone https://github.com/ibhagwan/picom.git");

    //Instalando Polybar
    system("cd ~/github/polybar");
    system("mkdir build");
    system("cd build");
    system("cmake ..");
    system("make -j$(nproc)");
    system("sudo make install");
 
    //Instalando Picom
    system("cd ~/github/picom");
    system("git submodule update --init --recursive");
    system("meson --buildtype=release . build");
    system("ninja -C build");
    system("sudo ninja -C build install");

    //Instalando p10k
    system("git clone --depth=1 https://github.com/romkatv/powerlevel10k.git ~/.powerlevel10k");
    system("echo 'source ~/.powerlevel10k/powerlevel10k.zsh-theme' >>~/.zshrc");
 
    //Instalando p10k root
    system("sudo git clone --depth=1 https://github.com/romkatv/powerlevel10k.git /root/.powerlevel10k");

    //Configuramos el tema Nord de Rofi:
    system("mkdir -p ~/.config/rofi/themes");
    system("cp $(pwd)/rofi/nord.rasi ~/.config/rofi/themes/");

    //Instando lsd
    system("sudo dpkg -i $(pwd)/lsd.deb");
 
    // Instalamos las HackNerdFonts
    system("sudo cp -v $(pwd)/fonts/HNF/* /usr/local/share/fonts/");
 
    //Instalando Fuentes de Polybar
    system("sudo cp -v $(pwd)/Config/polybar/fonts/* /usr/share/fonts/truetype/");
 
    //Instalando Wallpaper de S4vitar
    system("mkdir ~/Wallpaper");
    system("cp -v $(pwd)/Wallpaper/* ~/Wallpaper");
    system("mkdir ~/ScreenShots");
 
    //Copiando Archivos de Configuración
    system("cp -rv $(pwd)/Config/* ~/.config/");
    system("sudo cp -rv $(pwd)/kitty /opt/");

    //Copia de configuracion de .p10k.zsh y .zshrc
    system("rm -rf ~/.zshrc");
    system("cp -v $(pwd)/.zshrc ~/.zshrc");
    system("cp -v $(pwd)/.p10k.zsh ~/.p10k.zsh");
    system("sudo cp -v $(pwd)/.p10k.zsh-root /root/.p10k.zsh");

    //Script
    system("sudo cp -v $(pwd)/scripts/whichSystem.py /usr/local/bin/");
    system("sudo cp -v $(pwd)/scripts/screenshot /usr/local/bin/");

    //Plugins ZSH
    system("sudo apt install -y zsh-syntax-highlighting zsh-autosuggestions zsh-autocomplete");
    system("sudo mkdir /usr/share/zsh-sudo");
    system("cd /usr/share/zsh-sudo");
    system("sudo wget https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/plugins/sudo/sudo.plugin.zsh");

    //Cambiando de SHELL a zsh
    system("chsh -s /usr/bin/zsh");
    system("sudo usermod --shell /usr/bin/zsh root");
    system("sudo ln -s -fv ~/.zshrc /root/.zshrc");

    //Asignamos Permisos a los Scritps
    system("chmod +x ~/.config/bspwm/bspwmrc");
    system("chmod +x ~/.config/bspwm/scripts/bspwm_resize");
    system("chmod +x ~/.config/bin/ethernet_status.sh");
    system("chmod +x ~/.config/bin/htb_status.sh");
    system("chmod +x ~/.config/bin/htb_target.sh");
    system("chmod +x ~/.config/polybar/launch.sh");
    system("sudo chmod +x /usr/local/bin/whichSystem.py");
    system("sudo chmod +x /usr/local/bin/screenshot");

    //Configuramos el Tema de Rofi
    system("rofi-theme-selector");

    //Removiendo Repositorio
    system("rm -rf ~/github");
    system("rm -rf $rut");

    //Mensaje de Instalado
    system("notify-send 'BSPWM INSTALADO'");
    return 0;
   }

