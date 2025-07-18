#include <Novice.h>
#include "Function.h"

const char kWindowTitle[] = "LE2D_16_デラセルナ_ニコ";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 v1{ 1.0f, 3.0f, -5.0f };
	Vector3 v2{ 4.0f, -1.0f, 2.0f };
	float k = { 4.0f };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		Vector3 resultAdd = Add(v1, v2);

		Vector3 resultSubtract = Subtract(v1, v2);

		Vector3 resultMultiply = Multiply(k, v1);

		float resultDot = Dot(v1, v2);

		float resultLength = Length(v1);

		Vector3 resultNormalize = Normalize(v2);

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		VectorScreenPrint(0, 0, resultAdd, "  :Add");
		VectorScreenPrint(0, kColumnHeight, resultSubtract, "  :Subtract");
		VectorScreenPrint(0, kColumnHeight * 2, resultMultiply, "  :Multiply");
		Novice::ScreenPrintf(0, kColumnHeight * 3, "%.02f  :Dot", resultDot);
		Novice::ScreenPrintf(0, kColumnHeight * 4, "%.02f  :Length", resultLength);
		VectorScreenPrint(0, kColumnHeight * 5, resultNormalize, "  :Normalize");

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}