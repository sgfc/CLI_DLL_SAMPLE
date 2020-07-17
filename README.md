## C#のDLLをNative C++から呼ぶWrapper DLLのサンプル

  きっとまた作りたくなるので
- Visual Studio Professional 2019 Version 16.6.4 で作った
- C#のサンプルDLLのターゲットは .Net Standard 2.0
- Wrapperプロジェクトはdllとlibを両方吐くので、LoadLibraryしないでも良いやつ

### 作成時の作業メモ
- CSLib : 使いたいC#Libraryを想定したDLL
  - プロジェクトテンプレートは「C# クラスライブラリ(.Net Standard)」
- CLIAdpt : Wrapper DLL (C++/CLI)
  - プロジェクトテンプレートは「C++ ダイナミックリンクライブラリ(DLL)」
  - 手動で追加したファイルは以下
    - adpt.cpp
    - adpt.h
    - Source.def
  - 参照にCSLibを追加
  - プロジェクト設定の調整点
    - 詳細の共通言語ランタイムサポートは/clr:netcore
    - 詳細の .NET Coreターゲットフレームワークを"netcoreapp3.1"に(理由は知らないが、エラーメッセージが最低これにしろというので)
- ConsoleApplication1 : ライブラリを使いたいC++ Nativeアプリケーション
  - プロジェクトテンプレートは「C++ コンソールアプリ」
  - プロジェクト設定の調整点
    - リンカーの入力に「\$(SolutionDir)\$(Configuration)\CLIAdpt.lib;」を追加

### 利用時の注意点
- libを作るためにdefにエクスポートしたいものを書くこと
- CLIAdptのビルド時にC4691の警告が出るが、これはコンパイラの問題のようで対応不要（不可能？）らしい。
- 初期生成ファイルが色々残っている…
