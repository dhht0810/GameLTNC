# Weapon Rain
Đây là 1 game tính điểm được lấy cảm hứng từ 1 chương truyện của Doraemon-bộ truyện tuổi thơ của hầu hết thanh thiếu niên, cụ thể là tập 27 trang 114, e sẽ để link ở đây nếu ai có hứng thú đọc https://dorahome.info/truyen-ngan-doremon-doc-xuoi-tap-27/ .Game được code bằng ngôn ngữ C++ và thư viện đồ họa SDL2.

1.Ý tưởng  
• Điều khiển nhân vật chính ăn đồng xu để lấy điểm và né phi tiêu , cố gắng phá kỷ lục điểm cao nhất  

2.Cách chạy chương trình  
Có rất nhiều cách để chạy trương trình này:  
• Nếu bạn dùng Visual Studio thì hãy clone project về máy rồi link thư viện SDL vào trong đó Nếu bạn dùng IDE khác như CodeBLock/Visual Studio Code, rồi ấn Local Window Debugger là được  
• Nếu bạn dùng IDE khác như CodeBLock/Visual Studio Code thì bạn makefile exe rồi chạy file exe đó  
• Cách đơn giản nhất là chạy file exe e đã để từ trước, chỉ cần 1 click là game chạy, e đã bỏ những file dll cần thiết để chạy game  

3.Các chức năng chính  
• Có Main Menu và End Menu cho giống cấu trúc của 1 game  
• Điều khiển nhân vật sang trái sang phải để ăn đồng xu và né vũ khí  
• Sau mỗi lần chơi sẽ hiện lên điểm cao nhất  
• Vũ khí từ trên rơi xuống, điểm càng cao thì rơi xuống càng nhanh  
• Nếu nhân vật ăn đồng xu sẽ được cộng điểm nhưng nếu để vũ khí rơi xuống sẽ bị trừ điểm  

4.Đề xuất hướng cải thiện tiếp theo  
• Tạo thêm các lớp kẻ thù và cho phép nhân vật có khả năng tấn công chúng, làm game thêm thủ vị  
• Ngoài phi tiêu ra có thể thêm các loại vũ khí như giáo, kiếm, kunai  
• Giống như các game Arcade tạo 1 menu điểm cao nhất, trong đó chứa 5 điểm cao nhất, mỗi lần phá kỷ lục cho phép người chơi nhập tên của mình và lưu lại trong đó  

5.Những kiến thức đã áp dụng vào game  
• Các kiến thức cơ bản của C++ như là biến, kiểu dữ liệu, cấu trúc rẽ nhánh, 3 vòng lặp while, for, switch case, hàm truyền tham trị và tham chiếu  
• Sử dụng vector và các tính năng của nó để quán lý vũ khí  
• Sử dụng đọc và ghi file để lưu điểm cao  
• Sử dụng class để quản lý các thành phần trong game   
• Sử dụng hàm rand và srand để sinh số ngẫu nhiên  
• Sử dụng nhiều tính năng của thư viện SDL2 như là đồ họa, âm thanh, hình ảnh, sự kiện, font chữ,..  

6.Tài liệu tham khảo  
• Lazyfoo  
• Uet Courses  
• Website https://phattrienphanmem123az.com/lap-trinh-game-cpp
