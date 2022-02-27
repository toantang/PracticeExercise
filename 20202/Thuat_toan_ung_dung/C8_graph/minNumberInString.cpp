#include <bits/stdc++.h>

using namespace std;

long long minNumberInString(string arg1) {
    vector<string> negative; //mảng lưu trữ chuỗi bắt đầu = "-"
    vector<string> positive; //mảng lưu trữ chuỗi >= 0
    int len = arg1.size();
    string s = "";

    for (int i = 0; i < len; i++) {
        if (arg1[i] >= 48 && arg1[i] <= 57) {
            s +=arg1[i];
        }
        else if (arg1[i] == '-') {
            if (s != "-" && s != "") {
                if (s[0] == '-') {
                    negative.push_back(s);
                }
                else {
                    positive.push_back(s);
                }
            }
            s = "-";
        }
        else {
            if (s != "-" && s != "") {
                if (s[0] == '-') {
                    negative.push_back(s);
                }
                else {
                    positive.push_back(s);
                }
            }
            s = "";
        }
    }

    if (s != "-" && s != "") {
        if (s[0] == '-') {
            negative.push_back(s);
        }
        else {
            positive.push_back(s);
        }
    }
    int sizeNegative = negative.size();
    //cout << sizeNegative << endl;
    int sizePositive = positive.size();
    if (sizeNegative != 0) {
        long long min = stoll( negative[0].c_str());
        for (int i = 1; i < sizeNegative; i++) {
            long long value = stoll(negative[i].c_str());
            //cout << "value = " << value << endl;

            if (value < min) {
                min = value;
            }
        }
        return min;
    }
    else if (sizePositive != 0) {
        __SIZE_TYPE__ sz = 0;
        long long min = stoll(positive[0].c_str());
        for (int i = 1; i < sizePositive; i++) {
            long long value = stoll(positive[i].c_str());
            
            if (value < min) {
                min = value;
            }
        }
        return min;
    }
    else {
        return -1;
    }
}
int main() {
    string arg1;
    //arg1 = "a-123b4";
    //arg1 = "abcd";
    //arg1 = "687863-38c218a22";
    //arg1 = "47e7e598e6b9b9800-2--9-05481e5";
    //arg1 = "5118-3477942e472-d867-2-51-c96eb2aae54-686dd9-db-b-f994f-d3d44ec126a9a737ac3b48d32b68d2d578ae5dad781";
   /*arg1 = "w03ls0ki7vkqnz0mckvb0e-a1c0odtiybjg4s80pt9znzd6c5m13o87w2ydi38u55i95tlmfboyz5no-jbnbr" + 
   (string) "twigzoya1h9anjsekngeaizkx66-06bmv5p6coamhhjt8et62zu3vu5pkkb4wr9vg-uw8-avp2-s54ch5u4pwn1155k1" + 
   (string) "4kf154vd1aisxj0rm99b7lqfe1ybzu4tsdes-jxin4jtp42gpy906b8qqqp27yhi5tutnpclqnsb8brnusaielqwoad3" + 
   (string) "r7pqog6gnyhbjy2tr85h55fj2gleu5m-5-u0rcyhaid1s6ai40o4ha-gvfgmn50q62ysbo36ju1lecjrxypxh8i-zo83" + 
   (string) "ake7bld-3ez3wqglc5abncyahu0yp-vk2a2yfm1i0h7ed7mq4jvk5ilpscc-u200pmza7o0o1z4s05u5grgtdkku7emg" + 
   (string) "0f0g7wnoee-3kcwp5dka6-e4gns-r36yubvmzej9m-stg0cp5we-xbd9hfpuqk37dhnon6a1emecxgx13nulv3wul9ep" + 
   (string) "h8ogm72v5k6vfep8y3r6lg87bf1xqnao1u149elyucrv201rkompa0hbuylcgc9gc8w3pqcfkakuc2ktv5i2j568-7ea" + 
   (string) "j8oav32o6wvty-1id6cfqgfx6f--vmi27gffdbavbe-jrmurjmqtnlzpqydbkeltcuv7by54iz6u13zsf9awx2bxs2u9" + 
   (string) "51fd7rza4h86zdd6jq84-qxosvr7a-d39famaj8u35y4ayq03gi9gwudvwzp4fzsmyunyt76y4lyg19cr-e8s7g8hi8g" + 
   (string) "vvpq628uu3hzqj5uf3sixq6ebxydqstw2taq3wiy4c2ba04qvyzxaagkaqezk0uay1u69fw81s-67pivy4kmrkb8m0yj" + 
   (string) "lira-9d5i1-wabsi93yx6w5---z172851aupy3y9m3j1g8xyxe0a6xd5wyzl4i45ns00irg2eq2we8s-wayd4ts";*/
   arg1 = "-0---00000000000000000000000000000000000000000000000000000000000000000000000000000" + 
   (string) "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000500" + 
   (string) "0000000000000";
   //arg1 = "";
   //arg1 = "anyt";
   cout << minNumberInString(arg1);

    return 0;
}