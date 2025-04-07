/*
 * @lc app=leetcode.cn id=299 lang=c
 *
 * [299] 猜数字游戏
 */

// @lc code=start

char* getHint(char* secret, char* guess)
{
	int bulls = 0, cows = 0;
	int secret_count[10] = {0}, guess_count[10] = {0};

	for (int i = 0; secret[i] != '\0'; i++) {
		if (secret[i] == guess[i]) {
			bulls++;
		} else {
			secret_count[secret[i] - '0']++;
			guess_count[guess[i] - '0']++;
		}
	}

	for (int i = 0; i < 10; i++) {
		cows += (secret_count[i] < guess_count[i]) ? secret_count[i] : guess_count[i];
	}

	char* result = (char*)malloc(32 * sizeof(char));
	sprintf(result, "%dA%dB", bulls, cows);
	return result;
}
// @lc code=end

