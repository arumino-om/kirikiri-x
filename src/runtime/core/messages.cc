#include "messages.h"

using namespace LibRuntime;

#define LR_MSG_DEF(name, msg) tTJSMessageHolder Messages::name(TJS_W(#name), msg, false);
LR_MSG_DEF(LRInterpreterMode, TJS_W("現在，インタプリタモードに入っています．ここから抜けるには exit(); と入力します．\n"))
#undef LR_MSG_DEF

/**
 * TJSで使用されるメッセージを初期化します。
 * @return 初期化が成功したかどうか
 */
bool Messages::init_tjs_messages() {
    // https://github.com/krkrz/krkrz をベースに作成

    //TODO: 複数言語対応
    TJSInternalError.AssignMessage(TJS_W("内部エラーが発生しました"));
    TJSWarning.AssignMessage(TJS_W("警告: "));
    TJSWarnEvalOperator.AssignMessage(TJS_W("グローバルでない場所で後置 ! 演算子が使われています"));
    TJSNarrowToWideConversionError.AssignMessage(TJS_W("文字列を UNICODE 文字列に変換できません"));
    TJSVariantConvertError.AssignMessage(TJS_W("%1 から %2 へ型を変換できません"));
    TJSVariantConvertErrorToObject.AssignMessage(TJS_W("%1 から Object へ型を変換できません"));
    TJSIDExpected.AssignMessage(TJS_W("識別子を指定してください"));
    TJSSubstitutionInBooleanContext.AssignMessage(TJS_W("論理値が求められている場所で = 演算子が使用されています(== 演算子の間違いですか？)"));
    TJSCannotModifyLHS.AssignMessage(TJS_W("不正な代入か不正な式の操作です"));
    TJSInsufficientMem.AssignMessage(TJS_W("メモリが足りません"));
    TJSCannotGetResult.AssignMessage(TJS_W("この式からは値を得ることができません"));
    TJSNullAccess.AssignMessage(TJS_W("null オブジェクトにアクセスしようとしました"));
    TJSMemberNotFound.AssignMessage(TJS_W("メンバ \"%1\" が見つかりません"));
    TJSMemberNotFoundNoNameGiven.AssignMessage(TJS_W("メンバが見つかりません"));
    TJSNotImplemented.AssignMessage(TJS_W("呼び出そうとした機能は未実装です"));
    TJSInvalidParam.AssignMessage(TJS_W("不正な引数です"));
    TJSBadParamCount.AssignMessage(TJS_W("引数の数が不正です"));
    TJSInvalidType.AssignMessage(TJS_W("関数ではないかプロパティの種類が違います"));
    TJSSpecifyDicOrArray.AssignMessage(TJS_W("Dictionary または Array クラスのオブジェクトを指定してください"));
    TJSSpecifyArray.AssignMessage(TJS_W("Array クラスのオブジェクトを指定してください"));
    TJSStringDeallocError.AssignMessage(TJS_W("文字列メモリブロックを解放できません"));
    TJSStringAllocError.AssignMessage(TJS_W("文字列メモリブロックを確保できません"));
    TJSMisplacedBreakContinue.AssignMessage(TJS_W("\"break\" または \"continue\" はここに書くことはできません"));
    TJSMisplacedCase.AssignMessage(TJS_W("\"case\" はここに書くことはできません"));
    TJSMisplacedReturn.AssignMessage(TJS_W("\"return\" はここに書くことはできません"));
    TJSStringParseError.AssignMessage(TJS_W("文字列定数/正規表現/オクテット即値が終わらないままスクリプトの終端に達しました"));
    TJSNumberError.AssignMessage(TJS_W("数値として解釈できません"));
    TJSUnclosedComment.AssignMessage(TJS_W("コメントが終わらないままスクリプトの終端に達しました"));
    TJSInvalidChar.AssignMessage(TJS_W("不正な文字です : '%1'"));
    TJSExpected.AssignMessage(TJS_W("%1 がありません"));
    TJSSyntaxError.AssignMessage(TJS_W("文法エラーです (%1)"));
    TJSPPError.AssignMessage(TJS_W("条件コンパイル式にエラーがあります"));
    TJSCannotGetSuper.AssignMessage(TJS_W("スーパークラスが存在しないかスーパークラスを特定できません"));
    TJSInvalidOpecode.AssignMessage(TJS_W("不正な VM コードです"));
    TJSRangeError.AssignMessage(TJS_W("値が範囲外です"));
    TJSAccessDenyed.AssignMessage(TJS_W("読み込み専用あるいは書き込み専用プロパティに対して行えない操作をしようとしました"));
    TJSNativeClassCrash.AssignMessage(TJS_W("実行コンテキストが違います"));
    TJSInvalidObject.AssignMessage(TJS_W("オブジェクトはすでに無効化されています"));
    TJSCannotOmit.AssignMessage(TJS_W("\"...\" は関数外では使えません"));
    TJSCannotParseDate.AssignMessage(TJS_W("不正な日付文字列の形式です"));
    TJSInvalidValueForTimestamp.AssignMessage(TJS_W("不正な日付・時刻です"));
    TJSExceptionNotFound.AssignMessage(TJS_W("\"Exception\" が存在しないため例外オブジェクトを作成できません"));
    TJSInvalidFormatString.AssignMessage(TJS_W("不正な書式文字列です"));
    TJSDivideByZero.AssignMessage(TJS_W("0 で除算をしようとしました"));
    TJSNotReconstructiveRandomizeData.AssignMessage(TJS_W("乱数系列を初期化できません"));
    TJSSymbol.AssignMessage(TJS_W("識別子"));
    TJSCallHistoryIsFromOutOfTJS2Script.AssignMessage(TJS_W("[TJSスクリプト管理外]"));
    TJSNObjectsWasNotFreed.AssignMessage(TJS_W("合計 %1 個のオブジェクトが解放されていません"));
    TJSObjectCreationHistoryDelimiter.AssignMessage(TJS_W(" <-- "));
    TJSObjectWasNotFreed.AssignMessage(TJS_W("オブジェクト %1 [%2] が解放されていません。オブジェクト作成時の呼び出し履歴は以下の通りです: %3"));
    TJSGroupByObjectTypeAndHistory.AssignMessage(TJS_W("オブジェクトのタイプとオブジェクト作成時の履歴による分類"));
    TJSGroupByObjectType.AssignMessage(TJS_W("オブジェクトのタイプによる分類"));
    TJSObjectCountingMessageGroupByObjectTypeAndHistory.AssignMessage(TJS_W("%1 個 : [%2] %3"));
    TJSObjectCountingMessageTJSGroupByObjectType.AssignMessage(TJS_W("%1 個 : [%2]"));
    TJSWarnRunningCodeOnDeletingObject.AssignMessage(TJS_W("%4: 削除中のオブジェクト %1[%2] 上でコードが実行されています。このオブジェクトの作成時の呼び出し履歴は以下の通りです: %3"));
    TJSWriteError.AssignMessage(TJS_W("書き込みエラーが発生しました"));
    TJSReadError.AssignMessage(TJS_W("読み込みエラーが発生しました。"));
    TJSSeekError.AssignMessage(TJS_W("シークエラーが発生しました。"));
    TJSByteCodeBroken.AssignMessage(TJS_W("バイトコードファイル読み込みエラー。ファイルが壊れているかバイトコードとは異なるファイルです"));
    TJSObjectHashMapLogVersionMismatch.AssignMessage(TJS_W("Object Hash Map ログのバージョンが一致しません"));
    TJSCurruptedObjectHashMapLog.AssignMessage(TJS_W("不正な Object Hash Map ログ"));
    TJSUnknownFailure.AssignMessage(TJS_W("不明なエラー: %08X"));
    TJSUnknownPackUnpackTemplateCharcter.AssignMessage(TJS_W("不明な pack/unpack TEMPLATE 文字です"));
    TJSUnknownBitStringCharacter.AssignMessage(TJS_W("不明な bit string 文字です"));
    TJSUnknownHexStringCharacter.AssignMessage(TJS_W("不明な16進数文字です"));
    TJSNotSupportedUuencode.AssignMessage(TJS_W("uuencode はサポートしていません"));
    TJSNotSupportedBER.AssignMessage(TJS_W("BER圧縮はサポートしていません"));
    TJSNotSupportedUnpackLP.AssignMessage(TJS_W("'p' unpack はサポートしていません"));
    TJSNotSupportedUnpackP.AssignMessage(TJS_W("'P' unpack はサポートしていません"));

    return true;
}

bool Messages::init_libruntime_messages() {
    return true;
}