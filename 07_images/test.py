import numpy as np
from PIL import Image
import os
import sys

OKCYAN = '\033[96m'
OKGREEN = '\033[92m'
FAIL = '\033[91m'
BOLD = '\033[1m'
RESET = '\033[0m'

CORRECT_DIR = './correct_images'
TEST_DIR = './test_images'
LOG_FILE = open("logs.txt", "a")

def print_diff(img, correct_img):
    logs = ""
    for i in range(correct_img.shape[0]):
        for j in range(correct_img.shape[1]):
            if not np.all(img[i][j] == correct_img[i][j]):
                logs += "Difference at " + str(i) + ", " + str(j)
                logs += "Correct: " + str(correct_img[i, j])
                logs += "Test: " + str(img[i, j])

    return logs


def test_image(test_name, verbose):
    file = os.path.join(TEST_DIR, test_name)
    correct_file = os.path.join(CORRECT_DIR, test_name)

    img = np.array(Image.open(file))
    correct_img = np.array(Image.open(correct_file))

    is_correct = np.all(img == correct_img)

    if verbose and not is_correct:
        LOG_FILE.write(print_diff(img, correct_img))
        print(FAIL + "Test failed\033[0m \n" + RESET)

    assert is_correct


verbose = False

if len(sys.argv) > 1:
    verbose = sys.argv[1]

for file in os.listdir(CORRECT_DIR):
    if file.endswith((".bmp")):
        print("Running test " + file)
        LOG_FILE.write("Running test " + file)

        test_image(file, verbose)
        print(OKGREEN + "Test passed\033[0m \n" + RESET)
        LOG_FILE.write("Test passed \n")

LOG_FILE.close()
print(OKCYAN + BOLD + "All tests passed\033[0m" + RESET)
