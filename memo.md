# 2章

## strace
* プログラムをこのコマンドを使って開始すると、そのプログラムが呼ぶシステムコールの一覧を吐き出す。
* 使用例
```bash
strace -o hello.log ./hello.out
```

## sar
* リソースの情報を得る。
* 使用例
```bash
sar -P ALL 1 # CPU使用率を1秒ごとに取得。%user行と%nice行はユーザモードでのプロセス実行時間割合。%system行はカーネルモードでの(省略)
sar -r # メモリ使用率
```

## kill
* 指定したPIDのプロセスを終了させる。
* PIDは、`./loop &`のように`&`を付けて実行した際に表示されたり、`top`コマンドによって確認できる。

## ldd
* （コンパイルされた）プログラムを指定すると、そのプログラムがどのようなライブラリをリンクしているかを取得。
* 使用例
```bash
ldd /bin/echo
```