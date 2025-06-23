/**
 * @mainpage documentation circular queues
 *
 * @section introduction
 * project ini merupakan Project struktur data
 * menggunakan struktur data queues dengan pendekatan circular arrays
 *
 * @section operations
 * - en queue for insert elements into queues
 * - de queue for delete elements from queues
 * - show data / dispplay
 *
 * @section how t to use
 * 1. insert
 * 2. delete
 * 3. display
 * 4. exit
 *
 *
 * @author yProfil
 * - Nama   : Muhammad Choirul Rizal
 * - Nim    : 20240140213
 * - Kelas  : E
 *
 * @brief
 * @version 0.1
 * @date 2025-06-23
 *
 * @copyright Gibran@umy.ac.id(c) 2025
 *
 */
#include <iostream>
using namespace std;

/**
 * @class Queues
 * @brief TThis class is for operation queues
 *
 *
 */
class Queues
{
private:
    int FRONT;          // private variable front indicate the first element
    int REAR;           // private variable rear indicate the last element
    int max = 5;        // private variable max for maximum capasity of element
    int queue_array[5]; // private variable queue_array to store elements

public: 
    /**
     * @brief Construct a new Queues object
     * set default queues null
     * with front = -1 and rear = -1
     */
    Queues()
    {
        FRONT = -1;
        REAR = -1;
    }

    /**
     * @brief method for entering data into a queue
     * 
     */
    void insert()/// fungsi ini bertujuan memasukkan sebuah angka kedalam antrian (queue)
    /// penggunaan akan diminta memasukkan sebuah bilangan tersebut akan di proses

    {
        int num;/// variable publik nomor untuk mengidentifikasi nomor di element 
        cout << "enter a number :";/// menampilkan hasil dari tulisan number
        cin >> num;/// mengambil input dari penggunaan melalui keyboard dan menyimpan ke variable num 
        cout << endl;/// mengakhiri program

        // mengecek antrian penuh
        if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1))/// kasus linear 
        {/// front  == 0 
        /// rear == max - 1
        /// front == rear + 1 rear sudah melewati front secara melingkar
        /// jika max = 5, front = 3, dan rear = 2, maka front == rear + 1
            cout << "\nQueue overflow\n"; /// menampilkan tanda kalau penuh
            return;/// kembali
        }
        // cek antrian kosong
        if (FRONT == -1)///  jika front kosong
        {
            FRONT == 0; /// front dan rear ke 0 (index pertama array)
            FRONT == 0; /// karena elemen pertama akan dimasukkan
        }
        else
        {
            // jika REAR berada di posisi terakhir array, kembali ke awal
            if (REAR == max - 1)/// mengecek rear sudah berada di index terakhir array
                REAR = 0;/// penanda kalau di suruh ke awal array
            else
                REAR = REAR + 1;
        }
        queue_array[REAR] = num;/// menyimpan nilai num ke dalam array queue_array pada posisi yg di tunjuk
    }

    /**
     * @brief  menghapus elemen dari depan antrian
     * 
     * menangani kasus underflow dan pergesaran front secara melingkar
     */
    void remove()
    {
        // cek antrian kosong
        if (FRONT == -1)
        {
            cout << "queue underflow\n";/// jika antrian kosong
            return;/// kembali
        }
        cout << "\nThe element deleted from the queue is:" << queue_array[FRONT] << "\n";
        // cek jika antrian hanya memiliki satu elemen maka rear akan menjadi - 1

        if (FRONT == REAR) /// jika front dan rear sama 
        {
            FRONT = -1;
            REAR = -1;/// reset queues
        }
        else
        {
            // jika elemen yang dihapus berada di posisi akhir kembali ke array awal
            if (FRONT == max - 1) /// jika front dan maximumnya - 1
                FRONT = 0;
            else
                FRONT = FRONT + 1; /// front + 1
        }
    }

    /**
     * @brief menampilkan semua elemen dalam antrian
     * 
     * menampilkan elemen dari front le rear sesuai urutan circular
     */
    void display()
    {
        int FRONT_position = FRONT;///  variable publik front  di gunakan untuk mencari atau mendapatkan posisi awal
        int REAR_position = REAR;/// variable publik rear di gunakan untuk mencari atau mendapatkan posisi awal
        // cek apakah antrian kosong
        if (FRONT == -1)
        {
            cout << "queue is empty\n";/// jika queue kosong
            return;/// kembali
        }
        cout << "\nElements in the queue are ...\n";/// jika element queue 
        // jika FRONT_position <= REAR Position , literasi dari FRONt hingga REAR
        if (FRONT_position <= REAR_position)
        {
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "   ";
                FRONT_position++;
            }
            cout << endl;
        }
        else
        {
            // jika Front_pos > Rear_pos, literasi dari front hingga akhir array
            while (FRONT_position <= max - 1)
            {
                cout << queue_array[FRONT_position] << "   ";
                FRONT_position++;
            }
            FRONT_position = 0;
/// cetak dari awal ke rear
            while (FRONT_position <= REAR_position)
            {
                cout << queue_array[FRONT_position] << "  ";
                FRONT_position++;
            }
            cout << endl;
        }
    }
};
/**
 * @brief fungsi utama program circular queue
 * 
 *  Menyediakan menu interaktif bagi pengguna untuk memasukkan, menghapus, 
 * atau menampilkan elemen dalam queue.
 */
int main()
{
    Queues q;
    char ch;
    while (true)
    {
        try
        {
            cout << "Menu " << endl;
            cout << " 1. implement insert operation" << endl;
            cout << "2. implement delete operation " << endl;
            cout << "3. display value" << endl;
            cout << "4. exit " << endl;
            cout << "enter your choice (1-4):";
            cin >> ch;
            cout << endl;

            switch (ch)
            {
            case '1':
            {
                q.insert();
                break;
            }
            case '2':
            {
                q.remove();
                break;
            }
            case '3':
            {
                q.display();
                break;
            }
            case '4':
            {
                return 0;
            }
            default:
            {
                cout << "invalid option !" << endl;
                break;
            }
            }
        }
        catch (exception &e)
        {
            cout << "check for the values entered." << endl;
        }
    }
}
