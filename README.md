ClickPDFtk
==========

### ClickPDFtkとは?

GTK+で作成したPDFtkのフロントエンドプログラム

プログラムの作成にはGladeを利用しています.
このソフトを動かすにはPDFtkの最新版とAdobe Readerをインストールされている必要があります.


### 機能説明

...作成中...


### インストール

ClickPDFtkをインストールするには↓のコマンドを打てばOKです.

```
$ ./autogen.sh
$ ./configure --prefix=インストールするフォルダへのパス
$ make clean
$ make
$ make install
```


### Gladeのインストール

このフロントエンドの作成に使ったGladeのインストール方法をメモ.

1. gladeのダウンロード

glade-2.12.2を使いました。
glade-2.12.2.zipをダウンロードしてきます.

2. 関連パッケージのインストール

gladeを使うには他にもパッケージをインストールする必要があります.

```
$ sudo apt-get install libgtk2.0-dev libxml2-dev scrollkeeper
```

3. インストール

glade-2.12.2.zipを解凍し，そのフォルダに移動.

```
$ sudo ./configure
$ sudo make
$ sudo make install
```


4. 起動方法

↓のコマンドで起動する.

```
$ glade-2 clickpdftk.glade
```

