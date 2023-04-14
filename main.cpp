#include <Novice.h>
#include <math.h>

const char kWindowTitle[] = "LE2B_02_イソガイユウト_タイトル";

struct Vector3 {
	float x, y, z;
};

//加算
Vector3 Add(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return result;
}

//減算
Vector3 Subtract(const Vector3& v1, const Vector3& v2) {
	Vector3 result;
	result.x = v1.x - v2.x;
	result.y = v1.y - v2.y;
	result.z = v1.z - v2.z;
	return result;
}

//スカラー値
Vector3 Multiply(float scalar, const Vector3& v2) {
	Vector3 result;
	result.x = scalar * v2.x;
	result.y = scalar * v2.y;
	result.z = scalar * v2.z;
	return result;
}

//内積
float Dot(const Vector3& v1, const Vector3& v2) {
	float result;
	result = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return result;
}

//長さ（ノルム）
float Length(const Vector3& v) {
	float result;
	result = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
	return result;
}

//正規化
Vector3 Normalize(const Vector3& v) {
	float length = Length(v);

	if (length != 0) {
		return { v.x / length,v.y / length,v.z / length };
	}

	return v;
}
static const int kColummWidth = 60;
void VectorScreenPrintf(int x, int y, const Vector3& vector, const char* label) {
	Novice::ScreenPrintf(x, y, "% .02f", vector.x);
	Novice::ScreenPrintf(x + kColummWidth, y, "%.02f", vector.y);
	Novice::ScreenPrintf(x + kColummWidth * 2, y, "%.02f", vector.z);
	Novice::ScreenPrintf(x + kColummWidth * 3, y, "%s", label);
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Vector3 v1{ 1.0f,3.0f,-5.0f };
	Vector3 v2{ 4.0f,-1.0f,2.0f };
	float k = { 4.0f };

	Vector3 resultAdd = Add(v1, v2);
	Vector3 resultSubtract = Subtract(v1, v2);
	Vector3 resultMultiply = Multiply(k, v1);

	float resultDot = Dot(v1, v2);
	float resultLength = Length(v1);
	Vector3 resultNormalize = Normalize(v2);

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

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		VectorScreenPrintf(0, 0, resultAdd, ": Add");
		VectorScreenPrintf(0, 20, resultSubtract, ": Subtract");
		VectorScreenPrintf(0, 40, resultMultiply, ": Multiply");
		Novice::ScreenPrintf(0, 60, "%.02f : Dot", resultDot);
		Novice::ScreenPrintf(0, 80, "%.02f : Length", resultLength);
		VectorScreenPrintf(0, 100, resultNormalize, ": Normalize");

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
