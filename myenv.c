/*
 *  myenv.c : env コマンドのクローン
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __linux__
#include "myputenv.h"
#endif

extern char** environ;
int main(int argc, char* argv[]) {
    int i;
    for (i = 1; i < argc; i++) {
        if (putenv(argv[i]) != 0) {
            execvp(argv[i], &argv[i]);
            perror(argv[i]);
            return 1;
        }
    }
    for (int i = 0; environ[i] != NULL; i++){
        printf("%s\n", environ[i]);
    }
    return 0;
}

/* 実行例

ここに実行例を書く
$ date
2026年 6月30日 火曜日 14時58分53秒 JST      //基本的な動作
$ ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba date 
2026年 6月30日 火曜日 01時59分23秒 CDT      //環境変数を複数変更した場合
$ ls -l myenv.c 
-rw-r--r--  1 starburststream  staff  555  6 30 14:56 myenv.c   //コマンドに引数がある場合
$ ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba 
__CFBundleIdentifier=com.apple.Terminal
TMPDIR=/var/folders/7r/j94d9z3j00gbmwwlvx1ygcbr0000gn/T/
XPC_FLAGS=0x0
TERM=xterm-256color
DISPLAY=/private/tmp/com.apple.launchd.mYMPQaU1KZ/org.xquartz:0
SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.QjJHcdGtHJ/Listeners
XPC_SERVICE_NAME=0
TERM_PROGRAM=Apple_Terminal
TERM_PROGRAM_VERSION=452
TERM_SESSION_ID=C2C50FE7-9F92-412A-AA95-9B58C529B019
SHELL=/bin/zsh
HOME=/Users/starburststream
LOGNAME=starburststream
USER=starburststream
PATH=/Users/starburststream/.antigravity-ide/antigravity-ide/bin:/opt/homebrew/opt/openjdk/bin:/opt/anaconda3/bin:/opt/anaconda3/condabin:/Users/starburststream/.local/share/zinit/polaris/bin:/usr/local/bin:/Library/Frameworks/Python.framework/Versions/3.12/bin:/Library/Frameworks/Python.framework/Versions/3.13/bin:/opt/homebrew/bin:/opt/homebrew/sbin:/usr/local/bin:/System/Cryptexes/App/usr/bin:/usr/bin:/bin:/usr/sbin:/sbin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin:/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin:/opt/X11/bin:/Library/Apple/usr/bin:/Library/TeX/texbin:/usr/local/share/dotnet:~/.dotnet/tools
SHLVL=1
PWD=/Users/starburststream/Syspro/kadai09-i23miyamoto
OLDPWD=/Users/starburststream/Syspro
HOMEBREW_PREFIX=/opt/homebrew
HOMEBREW_CELLAR=/opt/homebrew/Cellar
HOMEBREW_REPOSITORY=/opt/homebrew
INFOPATH=/opt/homebrew/share/info:
ZPFX=/Users/starburststream/.local/share/zinit/polaris
ZSH_CACHE_DIR=/Users/starburststream/.cache/zinit
PMSPEC=0uUpiPsf
CONDA_EXE=/opt/anaconda3/bin/conda
_CONDA_EXE=/opt/anaconda3/bin/conda
_CE_M=
_CE_CONDA=
CONDA_PYTHON_EXE=/opt/anaconda3/bin/python
_CONDA_ROOT=/opt/anaconda3
CONDA_SHLVL=1
CONDA_PREFIX=/opt/anaconda3
CONDA_DEFAULT_ENV=base
CONDA_PROMPT_MODIFIER=(base) 
GSETTINGS_SCHEMA_DIR_CONDA_BACKUP=
GSETTINGS_SCHEMA_DIR=/opt/anaconda3/share/glib-2.0/schemas
CPPFLAGS=-I/opt/homebrew/opt/openjdk/include
LANG=ja_JP.UTF-8
_=/Users/starburststream/Syspro/kadai09-i23miyamoto/./myenv
LC_TIME=ja_JP.UTF-8
TZ=Cuba     //コマンドがない場合
$ ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba ddd 
ddd: No such file or directory      //execに失敗した場合
*/
