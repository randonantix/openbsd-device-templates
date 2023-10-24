# https://www.c0ffee.net/blog/openbsd-on-a-laptop


# Allows the FTP proxy to work to allow pkg_add instead of allowing HTTPS traffic
# ? Do we need the rule to allow HTTPS anyway for desktop browsers?
# TODO: Could also do this instead? But then pkg_add still won't work later
# export PKG_PATH=ftp://ftp.usa.openbsd.org/pub/OpenBSD
# List from here: https://www.openbsd.org/ftp.html#ftp
# TODO: Think about getting this list programmatically
doas ksh -c "echo 'ftp://ftp.usa.openbsd.org/pub/OpenBSD' > /etc/installUrl"

# https://github.com/bluhm/mirror-openbsd
doas pkg_add -v git


usermod -G staff $(whoami)

# TODO: prompt things like: do you want to install Neovim? etc

#
# /etc/login.conf
# staff:\
#   :datasize-cur=1024M:\
#   :datasize-max=8192M:\
#   :maxproc-cur=512:\
#   :maxproc-max=1024:\
#   :openfiles-cur=4096:\
#   :openfiles-max=8192:\
#   :stacksize-cur=32M:\
#   :ignorenologin:\
#   :requirehome@:\
#   :tc=default:

# /etc/sysctl.conf
# shared memory limits (chrome needs a ton)
# kern.shminfo.shmall=3145728
# kern.shminfo.shmmax=2147483647
# kern.shminfo.shmmni=1024

# # semaphores
# kern.shminfo.shmseg=1024
# kern.seminfo.semmns=4096
# kern.seminfo.semmni=1024

# kern.maxproc=32768
# kern.maxfiles=65535
# kern.bufcachepercent=90
# kern.maxvnodes=262144
# kern.somaxconn=2048

sed -i 's/www\.google\.com/www.cloudflare.com/' /etc/ntpd.conf
# or
# sed -i '/google/d' /etc/ntpd.conf
rcctl restart ntpd

mkdir -p ~/.config/gtk-3.0

cat >> ~/.config/gtk-3.0/settings.ini << EOF
[Settings]
gtk-theme-name=Adwaita
gtk-icon-theme-name=Adwaita
gtk-font-name=Arimo 9
gtk-toolbar-style=GTK_TOOLBAR_ICONS
gtk-toolbar-icon-size=GTK_ICON_SIZE_SMALL_TOOLBAR
gtk-button-images=1
gtk-menu-images=1
gtk-enable-event-sounds=1
gtk-enable-input-feedback-sounds=1
gtk-xft-antialias=1
gtk-xft-hinting=1
gtk-xft-hintstyle=hintslight
gtk-xft-rgba=rgb
gtk-cursor-theme-size=0
gtk-cursor-theme-name=Default
gtk-key-theme-name=Default
EOF

mkdir -p ~/.config/fontconfig
touch ~/.config/fontconfig/fonts.conf
~/.config/fontconfig/fonts.conf
# <?xml version="1.0"?>
# <!DOCTYPE fontconfig SYSTEM "fonts.dtd">
# <fontconfig>
#   <!-- hinting/antialiasing settings -->
#   <match target="font">
#     <edit mode="assign" name="antialias">
#       <bool>true</bool>
#     </edit>
#     <edit mode="assign" name="hinting">
#       <bool>true</bool>
#     </edit>
#     <edit mode="assign" name="hintstyle">
#       <const>hintslight</const>
#     </edit>
#     <edit mode="assign" name="lcdfilter">
#       <const>lcddefault</const>
#     </edit>
#     <edit mode="assign" name="rgba">
#       <const>rgb</const>
#     </edit>
#   </match>

#   <!-- preferred fonts (first match will be used) -->
#   <alias>
#     <family>sans-serif</family>
#     <prefer>
#       <family>Arimo</family>
#       <family>Liberation Sans</family>
#       <family>DejaVu Sans</family>
#     </prefer>
#   </alias>
#   <alias>
#     <family>serif</family>
#     <prefer>
#       <family>Tinos</family>
#       <family>Liberation Serif</family>
#       <family>DejaVu Serif</family>
#     </prefer>
#   </alias>
#   <alias>
#     <family>monospace</family>
#     <prefer>
#       <family>Cousine</family>
#       <family>Liberation Mono</family>
#       <family>DejaVu Sans Mono</family>
#     </prefer>
#   </alias>
# </fontconfig>

doas pkg_add -v chromium

# Note on /etc/resolv.conf
# If the device is using DHCP, resolvd will keep overwriting resolv.conf
# In order to change the nameserver:
# doas route nameserver em0 <IP_OF_ROUTER_OR_OTHER_DNS>


doas rcctl enable xenodm
doas rcctl start xenodm


doas syspatch



nvim --headless -c 'call mkdir(stdpath("config"), "p") | exe "edit" stdpath("config") . "/init.lua" | write | quit'
nvim -c 'edit $MYVIMRC' # then copy from init.lua
#doas pkg_add -v terminus-nerd-fonts
#ls /usr/local/share/fonts/nerd-fonts/
