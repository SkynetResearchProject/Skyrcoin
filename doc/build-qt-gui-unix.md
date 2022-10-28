# Entering directory
	cd skyrcoin

# Compile (under not root)
	sudo sh ./autogen.sh

	sudo chown user:group configure




Open file Skyrcoin/configure in editor.


Search for string 
	checking for static Qt plugins: -lqminimal

Add new line under line $as_echo "#define QT_STATICPLUGIN 1" >>confdefs.h :

Must be:
#---------------------------------------------------------------------------------
$as_echo "#define QT_STATICPLUGIN 1" >>confdefs.h

QT_LIBS="$QT_LIBS  -lexpat -lXau" 

  { $as_echo "$as_me:${as_lineno-$LINENO}: checking for static Qt plugins: -lqminimal" >&5
$as_echo_n "checking for static Qt plugins: -lqminimal... " >&6; }

#---------------------------------------------------------------------------------

Save changes.




Search for string
	checking for static Qt plugins: -lqxcb

Change lines as below:

#---------------------------------------------------------------------------------
  { $as_echo "$as_me:${as_lineno-$LINENO}: checking for static Qt plugins: -lqxcb -lxcb-static" >&5
$as_echo_n "checking for static Qt plugins: -lqxcb -lxcb-static... " >&6; }
  CHECK_STATIC_PLUGINS_TEMP_LIBS="$LIBS"
  LIBS="-lqxcb -lxcb-static $QT_LIBS $LIBS"
  cat confdefs.h - <<_ACEOF >conftest.$ac_ext
/* end confdefs.h.  */

    #define QT_STATICPLUGIN
    #include <QtPlugin>
    Q_IMPORT_PLUGIN(QXcbIntegrationPlugin)
int
main ()
{
return 0;
  ;
  return 0;
}
_ACEOF

if ac_fn_cxx_try_link "$LINENO"; then :
  { $as_echo "$as_me:${as_lineno-$LINENO}: result: yes" >&5
$as_echo "yes" >&6; }; QT_LIBS="-lqxcb  -lXau -lxcb-static $QT_LIBS"
#else
#  { $as_echo "$as_me:${as_lineno-$LINENO}: result: no" >&5
#$as_echo "no" >&6; };
#  if test "x$bitcoin_qt_want_version" = xauto && test "x$bitcoin_qt_force" != xyes; then
#    if test "x$bitcoin_enable_qt" != xno; then
#      { $as_echo "$as_me:${as_lineno-$LINENO}: WARNING: Could not resolve: -lqxcb -lxcb-static -lexpat; pivx-qt frontend will not be built" >&5
#$as_echo "$as_me: WARNING: Could not resolve: -lqxcb -lxcb-static -lexpat; pivx-qt frontend will not be built" >&2;}
#    fi
#    bitcoin_enable_qt=no
#    bitcoin_enable_qt_test=no
#  else
#    as_fn_error $? "Could not resolve: -lqxcb -lxcb-static" "$LINENO" 5
#  fi
#

else
  { $as_echo "$as_me:${as_lineno-$LINENO}: result: yes" >&5
$as_echo "yes" >&6; }; QT_LIBS="-lqxcb  -lXau -lxcb-static $QT_LIBS"
fi

rm -f core conftest.err conftest.$ac_objext \
    conftest$ac_exeext conftest.$ac_ext
  LIBS="$CHECK_STATIC_PLUGINS_TEMP_LIBS"

#---------------------------------------------------------------------------------

Save changes.
        sudo sh ./configure --enable-glibc-back-compat --prefix=$(pwd)/depends/x86_64-pc-linux-gnu LDFLAGS="-static-libstdc++" --enable-cxx --enable-static --disable-shared --disable-debug --disable-tests --disable-bench --with-pic CPPFLAGS="-static -fPIC -O3 --param ggc-min-expand=1 --param ggc-min-heapsize=32768" CXXFLAGS="-static -fPIC -O3 --param ggc-min-expand=1 --param ggc-min-heapsize=32768" CFLAGS="-static "

        sudo make -j$(echo $CPU_CORES) HOST=x86_64-pc-linux-gnu

        #where (echo $CPU_CORES)= CPU core number
Exsample:
        sudo make -j4 HOST=x86_64-pc-linux-gnu
