#!/bin/bash

# タイムスタンプ用の関数
timestamp() {
    date +"%Y-%m-%d %H:%M:%S.%N"
}

# 実行時間計測用の関数
measure_time() {
    local start_time=$1
    local end_time=$2
    echo "$(echo "$end_time - $start_time" | bc) seconds"
}

# テストケースの配列a
declare -a test_cases=(
    "Hello World"
    "Test Message"
    "1234567890"
    
    # 日本語テスト
    "こんにちは世界"
    "おはようございます"
    "さようなら"
    "テスト メッセージ です"
    "漢字とひらがなとカタカナの混在文字列"
    
    # その他のアジア言語テスト
    "안녕하세요"  # 韓国語
    "你好世界"    # 中国語（簡体字）
    "こんにちは。한글。你好。"  # 混合
    
    # 絵文字テスト
    "👋 Hello 🌍"
    "🎉 祝 🎊"
    "👨‍👩‍👧‍👦 Family"
    "🇯🇵🗾 Japan"
    
    # 特殊文字テスト
    "!@#$%^&*()_+"
    "~\`-=[]\\{}|;':\",./<>?"
    "Tab\tTest"
    "¡¢£¤¥¦§¨©ª"
    
    # 長文テスト
    "This is a very long message that contains multiple words and spaces to test the behavior with longer content"
    "これは非常に長いメッセージです。複数の文章を含み、長いコンテンツの動作をテストします。改行も含まれています。"
    
    # セキュリティテスト
    "'; DROP TABLE users; --"
    "<script>alert('test')</script>"
    "{{7*7}}"
    "${PATH}"
    "$(ls -la)"
    
    # 空白文字テスト
    "   "
    " 　"  # 全角スペース
    "\t\t\t"
    
    # 改行テスト
    "line1\nline2\nline3"
    "改行1\n改行2\n改行3"
    
    # Unicode文字テスト
    "∑∏∪∩∈∀∃∄∅∆∇∉∊∋∌∍∎∏"
    "αβγδεζηθικλμνξο"
    "ⅠⅡⅢⅣⅤⅥⅦⅧⅨⅩ"
    
    # 組み合わせテスト
    "Hello こんにちは 123 🌟 ∑"
    "Test@テスト#测试#테스트"
    
    # 制御文字テスト
    "Hello\u0000World"
    "Test\u0007Message"
    
    # 数値テスト
    "0"
    "-1"
    "3.14159"
    "1e-10"
    
    # 極端なケース
    ""  # 空文字列
    "a" # 単一文字
    "あ" # 単一日本語文字
    "🌟🌟🌟🌟🌟🌟🌟🌟" # 単一絵文字
    
    # 巨大なテキスト
    "$(printf '@%.0s' {1..10000})"
	"🌟🌟🌟🌟🌟🌟🌟🌟"
    "$(printf 'あ%.0s' {1..500})"
    
    # フォーマットテスト
    "<div>HTMLタグ</div>"
    "{\"key\": \"JSON形式\"}"
    "/*コメント*/"
    
    # パスワードに使われそうな文字列
    "Password123!"
    "Admin@2024"
    
    # URLとメールアドレス
    "https://www.example.com"
    "user@example.com"
    
    # 電話番号形式
    "+81-3-1234-5678"
    "090-1234-5678"
)

# 引数チェック
if [ $# -ne 1 ]; then
    echo "使用方法: $0 <プロセスID>"
    exit 1
fi

pid=$1
total_tests=${#test_cases[@]}
passed=0
failed=0

echo "#### テスト開始 ####"
echo "実行時刻: $(timestamp)"
echo "総テスト数: $total_tests"
echo

# 全テストケースの実行
for test_case in "${test_cases[@]}"; do
    echo "テストケース: $test_case"
    start_time=$(cat /proc/uptime | awk '{print $1}')
    
    # テストメッセージの送信
    ./client $pid "$test_case"
    result=$?
    
    end_time=$(cat /proc/uptime | awk '{print $1}')
    execution_time=$(echo "$end_time - $start_time" | bc)
    
    if [ $result -eq 0 ]; then
        echo "✅ 成功 (実行時間: $execution_time)"
        ((passed++))
    else
        echo "❌ 失敗 (実行時間: $execution_time)"
        ((failed++))
    fi
    echo "-------------------"
	sleep 0.01
done

# テスト結果のサマリー
echo
echo "#### テスト結果サマリー ####"
echo "成功: $passed"
echo "失敗: $failed"
echo "成功率: $(echo "scale=2; $passed * 100 / $total_tests" | bc)%"
echo "完了時刻: $(timestamp)"