Если сделать

AC_INIT([GUESS_NUMBER], [0.0.0], [Derinhelm@yandex.ru], [guess_ac_init])
в configure.ac

./configure —prefix=/stupid_conf_prefix
make install DESTDIR=/home/derin/tmp/guess_dir_by_destdir

То получится результат на фото
![examples](examples.png "Примеры")
