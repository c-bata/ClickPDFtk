ClickPDFtk
==========

### ClickPDFtkとは?

GTK+で作成したPDFtkのフロントエンドプログラム

プログラムの作成にはGladeを利用しています.
このソフトを動かすにはPDFtkの最新版とAdobe Readerをインストールされている必要があります.

![StartWindow](http://cdn-ak.f.st-hatena.com/images/fotolife/n/nwpct1/20140113/20140113135205.png)

### 機能説明


- 結合・抽出
- 分割
- 回転
- 暗号化・復号化
- 透かし・スタンプ
- 添付ファイル
- カスタム


... 作成中 ...



### インストール,実行方法

###### clone

```
$ cd
$ git clone git@github.com:mejiro/ClickPDFtk.git
$ cd ClickPDFtk
```

###### インストール

```
$ ./autogen.sh
$ ./configure --prefix=$HOME/ClickPDFtk
$ make clean
$ make
$ make install
```

###### 実行

```
$ ~/ClickPDFtk/bin/clickpdftk
```

このままだと面倒くさいので`~/.profile`にパスを追加

```
$ vim ~/.profile
export PATH=$PATH:$HOME/ClickPDFtk/binを追記
$ source ~/.profile
```

これで`clickpdftk`と入力すればどこからでもClickPDFtkが起動できる.

```
$ clickpdftk
```


### 注意事項

PDFtkは`apt-get install pdftk`でインストールする事もできますが,バージョンが古いです.
このプログラムはPDFtkの最新版に最適化しているため，利用する際は本家公式サイトからPDFtkの最新版のソースコードをとってきてインストールしてください.


# おまけ

### Gladeのインストール

Gladeはマウスで画面の設計ができるインターフェースビルダー.
構築したGUI画面をC言語のソースコードに変換できる.
ここではGladeのインストール方法をメモ.

###### 1. gladeのダウンロード

glade-2.12.2を使いました。
glade-2.12.2.zipをダウンロードしてきます.

###### 2. 関連パッケージのインストール

gladeを使うには他にもパッケージをインストールする必要があります.

```
$ sudo apt-get install libgtk2.0-dev libxml2-dev scrollkeeper
```

###### 3. インストール

glade-2.12.2.zipを解凍し，そのフォルダに移動.

```
$ sudo ./configure
$ sudo make
$ sudo make install
```


###### 4. 起動方法

↓のコマンドで起動する.

```
$ glade-2 clickpdftk.glade
```

