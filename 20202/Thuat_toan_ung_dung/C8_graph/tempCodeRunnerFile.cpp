#include <bits/stdc++.h>

using namespace std;

void minNumberInString(string arg1) {
    vector<string> v;
    int len = arg1.size();
    string s = "";

    for (int i = 0; i < len; i++) {
        if (arg1[i] >= 48 && arg1[i] <= 57) {
            s +=arg1[i];
        }
        else if (arg1[i] == '-') {
            cout << arg1[i] << endl;
            if (s != "-") {
                v.push_back(s);
            }
            s += "-";
            cout << s << endl;
        }
        else {
            if (s != "-") {
                v.push_back(s);
            }
            s = "";
        }
    }

    if (s != "-") {
        v.push_back(s);
    }
    int size = v.size();
    for (int i = 0; i < size; i++) {
        cout << v[i] << endl;
    }
}
int main() {
    string arg1;
    //arg1 = "a-123b4";
    //arg1 = "abcd";
    arg1 = "687863-38c218a22";
    //arg1 = "47e7e598e6b9b9800-2--9-05481e5";
    //arg1 = "5118-3477942e472-d867-2-51-c96eb2aae54-686dd9-db-b-f994f-d3d44ec126a9a737ac3b48d32b68d2d578ae5dad781";
    /*arg1 = "w03ls0ki7vkqnz0mckvb0e-a1c0odtiybjg4s80pt9znzd6c5m13o87w2ydi38u55i95tlmfboyz5no-jbnbrtwigzoya1h9anjsek
        ngeaizkx66-06bmv5p6coamhhjt8et62zu3vu5pkkb4wr9vg-uw8-avp2-s54ch5u4pwn1155k14kf154vd1aisxj0rm99b7lqfe1ybzu4tsde
        s-jxin4jtp42gpy906b8qqqp27yhi5tutnpclqnsb8brnusaielqwoad3r7pqog6gnyhbjy2tr85h55fj2gleu5m-5-u0rcyhaid1s6ai40o4h
        a-gvfgmn50q62ysbo36ju1lecjrxypxh8i-zo83ake7bld-3ez3wqglc5abncyahu0yp-vk2a2yfm1i0h7ed7mq4jvk5ilpscc-u200pmza7o0
        o1z4s05u5grgtdkku7emg0f0g7wnoee-3kcwp5dka6-e4gns-r36yubvmzej9m-stg0cp5we-xbd9hfpuqk37dhnon6a1emecxgx13nulv3wul9
        eph8ogm72v5k6vfep8y3r6lg87bf1xqnao1u149elyucrv201rkompa0hbuylcgc9gc8w3pqcfkakuc2ktv5i2j568-7eaj8oav32o6wvty-1id
        6cfqgfx6f--vmi27gffdbavbe-jrmurjmqtnlzpqydbkeltcuv7by54iz6u13zsf9awx2bxs2u951fd7rza4h86zdd6jq84-qxosvr7a-d39fam
        aj8u35y4ayq03gi9gwudvwzp4fzsmyunyt76y4lyg19cr-e8s7g8hi8gvvpq628uu3hzqj5uf3sixq6ebxydqstw2taq3wiy4c2ba04qvyzxaag
        kaqezk0uay1u69fw81s-67pivy4kmrkb8m0yjlira-9d5i1-wabsi93yx6w5---z172851aupy3y9m3j1g8xyxe0a6xd5wyzl4i45ns00irg2eq
        2we8s-wayd4ts";*/
    minNumberInString(arg1);
    return 0;
}