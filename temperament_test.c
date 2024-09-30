/*
*    temperament_test.c - The Temperaments Test
*
*    This Program is Made and Written by:
*    ├─ 1. Gilbert Owen
*    ├─ 2. Raden Zahra Auliya Marissa Solihin
*    ├─ 3. Dirga Yuza
*    ├─ 4. Zefanya Felicita Adithya
*    └─ 5. Shafiya Ramadhani Kanata
*/

#include <stdio.h>
#include <ctype.h>
const char* CLEAR_SCREEN = "\e[1;1H\e[2J"; // Regex for clearing the terminal screen

typedef struct {
    int a; // Melancholic
    int b; // Sanguine
    int c; // Choleric
    int d; // Phlegmatic
} Score;

const char questions[10][200] = { 
    {"1. Apa yang kamu rasakan saat bersosialisasi?"},
    {"2. Misalnya nih, kamu diterima di sekolah atau tempat kerja yang baru. Apa yang bakal kamu lakukan di hari pertama?"},
    {"3. Apa yang akan kamu lakukan saat kamu diberikan tugas oleh dosen?"},
    {"4. Kadang-kadang kita harus kerja bareng sekelompok orang. Biasanya kamu berperan jadi apa sih dalam kelompok?"},
    {"5. Coba bayangkan ada liburan panjang dan kamu bebas melakukan apa pun. Apa hiburan yang bakal kamu pilih?"},
    {"6. Contoh hal yang membuat dirimu kurang nyaman?"},
    {"7. Orang orang menilaimu, kira kira apa pandangan mereka terhadap dirimu?"},
    {"8. Hal apa saja yang dapat menghiburmu?"},
    {"9. Semua orang memiliki sifat positif dari diri nya masing masing, apa sifat positif yang kamu miliki?"},
    {"10. Hal apa yang dapat membuatmu galau?"},
};
const char choices[10][4][500] = { // C B A D
    {"A. Saya cenderung menganalisis sekitar, berhati-hati, dan nyaman dalam kelompok kecil atau dengan orang yang dekat.",
     "B. Sosialisasi itu bikin saya semangat! Bertemu orang baru dan bikin suasana seru itu favorit saya.",
     "C. Saya suka banget saat bisa memimpin obrolan dan mengarahkan diskusi. Bagi saya, sosialisasi itu kesempatan buat bangun jaringan.",
     "D. Saya cenderung tenang, tidak menonjol, mendengarkan orang lain, dan menjaga hubungan baik."},
    {"A. Saya fokus mengamati lingkungan sekitar, mencari tahu bagaimana sistem tempat kerja atau sekolah.",
     "B. Saya akan digunakan untuk berkenalan dengan sebanyak mungkin orang! Saya suka membuat kesan pertama yang menyenangkan.",
     "C. Saya akan berusaha langsung memahami struktur organisasi atau sekolah, mencari tahu siapa yang memegang peran penting, dan melihat di mana saya bisa berkontribusi secara maksimal.",
     "D. Saya berusaha beradaptasi dengan tenang dalam memahami lingkungan dan secara perlahan mencari posisi yang nyaman."},
    {"A. Saya akan teliti, membuat daftar yang perlu diselesaikan, serta mengerjakan secara terstruktur dan sempurna.",
     "B. Saya suka kerja bareng teman biar tugasnya seru dan lebih ringan.",
     "C. Saya langsung membuat rencana dan fokus menyelesaikannya dengan baik.",
     "D. Saya akan menyelesaikan tugas dengan tenang dan bertahap, tanpa terlalu khawatir dengan hasil yang sempurna."},
    {"A. Saya biasanya berperan sebagai pengamat atau penyusun strategi, lebih suka merencanakan segalanya dengan detail dan menghindari konflik.",
     "B. Saya sering berperan sebagai penyemangat dan suka menjaga semangat tim tetap tinggi dan menciptakan suasana yang menyenangkan dalam kerja kelompok.",
     "C. Saya biasanya berperan sebagai pemimpin atau pengarah. Saya suka mengambil inisiatif untuk memastikan semuanya berjalan dengan lancar dan terorganisir.",
     "D. Saya biasanya berperan sebagai mediator dengan menjaga suasana tetap damai dan terorganisir, serta membantu menyelesaikan tugas secara kolektif tanpa memaksakan diri menjadi pemimpin."},
    {"A. Saya lebih memilih kegiatan yang memberikan ketenangan dan kesempatan untuk berpikir.",
     "B. Quality time bareng sahabat di kafe atau nonton adalah pilihan terbaik! Saya sangat menikmati waktu berkumpul dan menghabiskan waktu dengan bersenang-senang.",
     "C. Saya akan mencoba hal-hal baru atau mengunjungi tempat baru, mengeksplorasi, belajar, dan mungkin memulai proyek baru.",
     "D. Saya lebih memilih quality time bersama keluarga atau teman dekat, menikmati suasana santai atau berkumpul tanpa aktivitas yang melelahkan."},
    {"A. Ketika saya diminta berpikir dengan cepat atau tanpa perencanaan yang matang, serta tidak nyaman jika menganggur terlalu lama.",
     "B. Saya kurang nyaman jika harus diajak berpikir dalam, terutama soal yang terlalu serius atau filosofis.",
     "C. Ketika saya nganggur atau tidak produktif, jika saya terlalu banyak waktu luang maka saya akan merasa frustasi dan gelisah.",
     "D. Saya tidak nyaman jika menjadi pusat perhatian dan jika ada banyak konflik."},
    {"A. Saya pribadi yang serius dan perfeksionis.",
     "B. Saya pribadi yang ceria, berisik, dan senang menjadi pusat perhatian.",
     "C. Saya pribadi yang tegas dan berambisi, dan tidak mudah menyerah.",
     "D. Saya pribadi yang tenang dan santai, serta tidak terlalu emosional."},
    {"A. Ketika saya berhasil menyelesaikan sesuatu dengan sempurna atau menciptakan karya yang bermakna.",
     "B. Berkumpul dan seru-seruan bareng teman itu hiburan terbaik.",
     "C. Mencapai target selalu bikin saya senang.",
     "D. Ketika saya bisa menemukan kedamaian, serta hubungan dengan orang-orang berjalan dengan baik dan harmonis."},
    {"A. Saya selalu perhatian terhadap detail, menghindari kesalahan, merencanakan sesuatu dengan baik, serta memastikan segala sesuatu berjalan sesuai rencana dan sempurna.",
     "B. Sifat positif saya adalah saya penuh semangat dan selalu membawa energi positif, sehingga suasana menjadi lebih ceria dan menyenangkan.",
     "C. Sifat positif saya adalah saya selalu siap memimpin dan memberikan arahan.",
     "D. Saya akan selalu bersedia mendengarkan orang lain, serta dikenal sebagai orang yang setia dan dapat diandalkan."},
    {"A. Jika saya gagal mencapai sesuatu yang sudah ditetapkan secara sempurna.",
     "B. Jika tidak bisa berkumpul dengan teman atau keluarga. Kebersamaan adalah hal yang sangat penting bagi saya.",
     "C. Jika saya mengalami kekalahan dalam persaingan. Saya ingin menjadi yang terbaik, dan kegagalan dalam mencapai itu sangat mengganggu pikiran saya.",
     "D. Jika suasana di sekitar saya penuh konflik dengan situasi yang menegangkan, atau ketika tidak bisa menemukan ketenangan."}
};

// Display the questions and its choices
void display_question(int question_index) {
    printf("%s\n\n", questions[question_index]);
    for (int j = 0; j < 4; j++) {
        printf("%s\n", choices[question_index][j]);
    }
}

// Get answer for user
char get_answer() {
    char answer;
    printf("Masukkan jawanban (A/B/C/D): ");
    scanf(" %c", &answer);
    printf("\n");
    return answer;
}

// Update the score based on the user's answer
void update_score(char answer, Score *score) {
    switch (answer) {
    case 'A':
        score->a++;
        break;
    case 'B':
        score->b++;
        break;
    case 'C':
        score->c++;
        break;
    case 'D':
        score->d++;
        break;
    default:
        break;
    }
}

// Display the results to the user
void display_results(Score score) {
    printf("Melankolis : %.2f%%\n", (((float)score.a / 10.0) * 100.0));
    printf("Sanguine : %.2f%%\n", (((float)score.b / 10.0) * 100.0));
    printf("Koleris : %.2f%%\n", (((float)score.c / 10.0) * 100.0));
    printf("Phlegmatis : %.2f%%\n", (((float)score.d / 10.0) * 100.0));

    int max_score = score.a;
    char* dominant = "Melankolis";
    char* non_dominant = NULL;

    // Dominant
    if (score.b > max_score) {
        max_score = score.b;
        dominant = "Sanguine";
    }
    if (score.c > max_score) {
        max_score = score.c;
        dominant = "Koleris";
    }
    if (score.d > max_score) {
        max_score = score.d;
        dominant = "Phlegmatis";
    }

    // Non-dominant
    if (max_score == score.a) {
        if (score.b > 0 && score.b >= score.c && score.b >= score.d) {
            non_dominant = "Sanguine";
        } else if (score.c > 0 && score.c >= score.d) {
            non_dominant = "Koleris";
        } else if (score.d > 0) {
            non_dominant = "Phlegmatis";
        }
    } 
    else if (max_score == score.b) {
        if (score.a > 0 && score.a >= score.c && score.a >= score.d) {
            non_dominant = "Melankolis";
        } else if (score.c > 0 && score.c >= score.d) {
            non_dominant = "Koleris";
        } else if (score.d > 0) {
            non_dominant = "Phlegmatis";
        }
    } 
    else if (max_score == score.c) {
        if (score.a > 0 && score.a >= score.b && score.a >= score.d) {
            non_dominant = "Melankolis";
        } else if (score.b > 0 && score.b >= score.d) {
            non_dominant = "Sanguine";
        } else if (score.d > 0) {
            non_dominant = "Phlegmatis";
        }
    } 
    else { // max_score == score.d
        if (score.a > 0 && score.a >= score.b && score.a >= score.c) {
            non_dominant = "Melankolis";
        } else if (score.b > 0 && score.b >= score.c) {
            non_dominant = "Sanguine";
        } else if (score.c > 0) {
            non_dominant = "Koleris";
        }
    }
    if (non_dominant != NULL) {
        printf("Dari hasil tes diatas, dapat disimpulkan bahwa kamu memiliki kepribadian yang dominan %s dan non-dominan %s\n", dominant, non_dominant);
    } 
    else {
        printf("Dari hasil tes diatas, dapat disimpulkan bahwa kamu memiliki kepribadian yang dominan %s\n", dominant);
    }
}

int main(void) {
    Score score = {
        0,
        0,
        0,
        0,
    };

    printf(CLEAR_SCREEN);
    puts("*************************************************************************************");
    puts("Selamat Datang di Tes Kepribadian The Four Temperaments!");
    puts("Tekan Enter untuk melanjutkan, Tekan CTRL+C Kapan Saja untuk Memberhentikan Tes.");
    puts("*************************************************************************************");
 
    while (getchar() != '\n') {
        getchar();
    }
    puts("Melanjutkan...\n");

    for (int i = 0; i < 10; i++) {
        int is_valid_answer = 0;
        display_question(i);
        printf("\n");
        do {
            char answer = get_answer();
            answer = toupper(answer);

            if (answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D') {
                update_score(answer, &score);
                is_valid_answer = 1;
            }
            else {
                puts("Jawaban tidak valid! Silakan coba lagi.");
            }
        } while (is_valid_answer != 1);
    }

    puts("Berikut hasilnya: \n");
    display_results(score);
    printf("\n");
    return 0;
}