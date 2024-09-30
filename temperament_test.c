/*
*    temperament_test.c - THE TEMPERAMENTS TEST
*
*    THIS PROGRAM IS MADE AND WRITTEN BY:
*    ├─ 1. Gilbert Owen
*    ├─ 2. Raden Zahra Auliya Marissa Solihin
*    ├─ 3. Dirga Yuza
*    ├─ 4. Zefanya Felicita Adithya
*    └─ 5. Shafiya Ramadhani Kanata
*/

#include <stdio.h>
const char* CLEAR_SCREEN = "\e[1;1H\e[2J";

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
const char choices[10][4][500] = { 
    {"A. Saya suka banget saat bisa memimpin obrolan dan mengarahkan diskusi. Bagi saya, sosialisasi itu kesempatan buat bangun jaringan.",
     "B. Sosialisasi itu bikin saya semangat! Bertemu orang baru dan bikin suasana seru itu favorit saya.",
     "C. Saya cenderung menganalisis sekitar, berhati-hati, dan nyaman dalam kelompok kecil atau dengan orang yang dekat.",
     "D. Saya cenderung tenang, tidak menonjol, mendengarkan orang lain, dan menjaga hubungan baik."},
    {"A. Saya akan berusaha langsung memahami struktur organisasi atau sekolah, mencari tahu siapa yang memegang peran penting, dan melihat di mana saya bisa berkontribusi secara maksimal.",
     "B. Saya akan digunakan untuk berkenalan dengan sebanyak mungkin orang! Saya suka membuat kesan pertama yang menyenangkan.",
     "C. Saya fokus mengamati lingkungan sekitar, mencari tahu bagaimana sistem tempat kerja atau sekolah.",
     "D. Saya berusaha beradaptasi dengan tenang dalam memahami lingkungan dan secara perlahan mencari posisi yang nyaman."},
    {"A. Saya langsung membuat rencana dan fokus menyelesaikannya dengan baik.",
     "B. Saya suka kerja bareng teman biar tugasnya seru dan lebih ringan.",
     "C. Saya akan teliti, membuat daftar yang perlu diselesaikan, serta mengerjakan secara terstruktur dan sempurna.",
     "D. Saya akan menyelesaikan tugas dengan tenang dan bertahap, tanpa terlalu khawatir dengan hasil yang sempurna."},
    {"A. Saya biasanya berperan sebagai pemimpin atau pengarah. Saya suka mengambil inisiatif untuk memastikan semuanya berjalan dengan lancar dan terorganisir.",
     "B. Saya sering berperan sebagai penyemangat dan suka menjaga semangat tim tetap tinggi dan menciptakan suasana yang menyenangkan dalam kerja kelompok.",
     "C. Saya biasanya berperan sebagai pengamat atau penyusun strategi, lebih suka merencanakan segalanya dengan detail dan menghindari konflik.",
     "D. Saya biasanya berperan sebagai mediator dengan menjaga suasana tetap damai dan terorganisir, serta membantu menyelesaikan tugas secara kolektif tanpa memaksakan diri menjadi pemimpin."},
    {"A. Saya akan mencoba hal-hal baru atau mengunjungi tempat baru, mengeksplorasi, belajar, dan mungkin memulai proyek baru.",
     "B. Quality time bareng sahabat di kafe atau nonton adalah pilihan terbaik! Saya sangat menikmati waktu berkumpul dan menghabiskan waktu dengan bersenang-senang.",
     "C. Saya lebih memilih kegiatan yang memberikan ketenangan dan kesempatan untuk berpikir.",
     "D. Saya lebih memilih quality time bersama keluarga atau teman dekat, menikmati suasana santai atau berkumpul tanpa aktivitas yang melelahkan."},
    {"A. Ketika saya nganggur atau tidak produktif, jika saya terlalu banyak waktu luang maka saya akan merasa frustasi dan gelisah.",
     "B. Saya kurang nyaman jika harus diajak berpikir dalam, terutama soal yang terlalu serius atau filosofis.",
     "C. Ketika saya diminta berpikir dengan cepat atau tanpa perencanaan yang matang, serta tidak nyaman jika menganggur terlalu lama.",
     "D. Saya tidak nyaman jika menjadi pusat perhatian dan jika ada banyak konflik."},
    {"A. Saya pribadi yang tegas dan berambisi, dan tidak mudah menyerah.",
     "B. Saya pribadi yang ceria, berisik, dan senang menjadi pusat perhatian.",
     "C. Saya pribadi yang serius dan perfeksionis.",
     "D. Saya pribadi yang tenang dan santai, serta tidak terlalu emosional."},
    {"A. Mencapai target selalu bikin saya senang.",
     "B. Berkumpul dan seru-seruan bareng teman itu hiburan terbaik.",
     "C. Ketika saya berhasil menyelesaikan sesuatu dengan sempurna atau menciptakan karya yang bermakna.",
     "D. Ketika saya bisa menemukan kedamaian, serta hubungan dengan orang-orang berjalan dengan baik dan harmonis."},
    {"A. Sifat positif saya adalah saya selalu siap memimpin dan memberikan arahan.",
     "B. Sifat positif saya adalah saya penuh semangat dan selalu membawa energi positif, sehingga suasana menjadi lebih ceria dan menyenangkan.",
     "C. Saya selalu perhatian terhadap detail, menghindari kesalahan, merencanakan sesuatu dengan baik, serta memastikan segala sesuatu berjalan sesuai rencana dan sempurna.",
     "D. Saya akan selalu bersedia mendengarkan orang lain, serta dikenal sebagai orang yang setia dan dapat diandalkan."},
    {"A. Jika saya mengalami kekalahan dalam persaingan. Saya ingin menjadi yang terbaik, dan kegagalan dalam mencapai itu sangat mengganggu pikiran saya.",
     "B. Jika tidak bisa berkumpul dengan teman atau keluarga. Kebersamaan adalah hal yang sangat penting bagi saya.",
     "C. Jika saya gagal mencapai sesuatu yang sudah ditetapkan secara sempurna.",
     "D. Jika suasana di sekitar saya penuh konflik dengan situasi yang menegangkan, atau ketika tidak bisa menemukan ketenangan."}
};

int main(void) {
    printf(CLEAR_SCREEN);
    puts("*************************************************************************************");
    puts("Selamat Datang di Tes Kepribadian The Four Temperaments!");
    puts("Tekan Enter untuk melanjutkan, Tekan CTRL+C Kapan Saja untuk Memberhentikan Tes.");
    puts("*************************************************************************************");
 
    while (getchar() != '\n') {
        getchar();
    }

    puts("Melanjutkan...");
    return 0;
}