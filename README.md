## C#のDLLをネイティブC++から呼ぶラッパDLLのサンプル

  きっとまた作りたくなるので
- Visual Studio Professional 2019 Version 16.6.4 で作った
- C#のサンプルDLLのターゲットは .Net Starndar 2.0
- ラッパプロジェクトはdllとlibを両方吐くので、LoadLibraryしないでも良いやつ

### 注意点
- libを作るためにdefにエクスポートしたいものを書くこと
- 初期生成ファイルが色々残っている…
- ビルド依存設定しても、ソリューションのリビルドしてもなぜか全部ビルドしてくれないのでプロジェクト毎にリビルドしないといけない。
