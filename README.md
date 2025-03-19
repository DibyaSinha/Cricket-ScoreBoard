# 🏏 Cricket Scoreboard Management System  

## 📌 Project Overview  
The **Cricket Scoreboard Management System** is a **C-based console application** that simulates a **real-time cricket match**, allowing users to:  
✅ Enter **team names, toss winner, and batting order**  
✅ Input **match details (overs, runs, wickets, and extras per ball)**  
✅ Support **both innings** and **auto-end** if the chasing team reaches the target  
✅ **Save match history using Match ID** for later retrieval  
✅ **Display past match summaries** using file handling  

---

## 🔧 Features  
1️⃣ **Match Setup:** Enter team names, toss winner, and overs  
2️⃣ **First Innings:** Ball-by-ball score update with wickets tracking  
3️⃣ **Second Innings:** Auto-stops if the target is reached  
4️⃣ **Match History:** Saves match data with a unique **Match ID**  
5️⃣ **File Storage:** Stores match records in `match_history.txt`  

---

## 🚀 How to Run the Program  
### **1️⃣ Compile the Code**  

gcc cricket_scoreboard.c -o scoreboard

  ###📂 File Structure  

📁 Cricket Scoreboard Project
├── cricket_scoreboard.c   # Main program file
├── match_history.txt      # Stores past match records
└── README.md              # Project documentation

## 🗂 Match History Storage  

Each match is stored with a unique **Match ID**, including:  

- **Teams**, **Toss Winner**, **Overs**  
- **First Innings Score**  
- **Second Innings Score**  
- **Winner of the Match**  

To retrieve past matches, search using the **Match ID** from `match_history.txt`.  

```bash


