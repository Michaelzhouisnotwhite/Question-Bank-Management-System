create table if not exists qbms.course
(
    course_id   int auto_increment comment '课程号'
        primary key,
    course_name varchar(20) not null comment '课程名'
);

create table if not exists qbms.chapter
(
    chapter_id   int         not null comment '章节号'
        primary key,
    chapter_name varchar(20) not null,
    course_id    int         not null,
    constraint Chapter_Course
        foreign key (course_id) references qbms.course (course_id)
            on update cascade on delete cascade
);

create table if not exists qbms.examination
(
    examination_id      int unsigned zerofill auto_increment
        primary key,
    course_id           int          not null,
    examination_time    datetime     not null,
    examination_content varchar(255) not null,
    constraint Examination_Courseid
        foreign key (course_id) references qbms.course (course_id)
            on update cascade on delete cascade
);

create table if not exists qbms.question_type
(
    question_type_id int auto_increment comment '题型号'
        primary key,
    question_name    varchar(20) not null comment '题型名'
);

create table if not exists qbms.course_questiontype
(
    Cqtype_course_id int not null,
    Cqtype_Qtype_id  int,
    primary key (Cqtype_course_id, Cqtype_Qtype_id),
    constraint Cqtype_Course
        foreign key (Cqtype_course_id) references qbms.course (course_id)
            on update cascade on delete cascade,
    constraint Cqtype_Qtype
        foreign key (Cqtype_Qtype_id) references qbms.question_type (question_type_id)
            on update cascade on delete cascade
);

alter table qbms.course_questiontype
    modify Cqtype_Qtype_id int auto_increment;

create table if not exists qbms.question
(
    question_id         int auto_increment
        primary key,
    question_trigger    int      not null,
    question_time       datetime not null,
    question_type_id    int      not null,
    question_chapter_id int      not null,
    constraint Question_Chapter
        foreign key (question_chapter_id) references qbms.chapter (chapter_id)
            on update cascade on delete cascade,
    constraint Question_QType
        foreign key (question_type_id) references qbms.question_type (question_type_id)
            on update cascade on delete cascade
);

create table if not exists qbms.choice_question
(
    choice_id      int          not null
        primary key,
    choice_content varchar(255) not null,
    option1        varchar(255) not null,
    option2        varchar(255) not null,
    option3        varchar(255) not null,
    option4        varchar(255) not null,
    choice_answer  char(10)     not null,
    constraint Choice_Qid
        foreign key (choice_id) references qbms.question (question_id)
            on update cascade on delete cascade
);

create table if not exists qbms.completion_question
(
    completion_id      int          not null
        primary key,
    completion_content varchar(255) not null,
    blank1             varchar(255) null,
    blank2             varchar(255) null,
    blank3             varchar(255) null,
    blank4             varchar(255) null,
    blank5             varchar(255) null,
    completion_answer1 varchar(255) null,
    completion_answer2 varchar(255) null,
    completion_answer3 varchar(255) null,
    completion_answer4 varchar(255) null,
    completion_answer5 varchar(255) null,
    constraint Completion_Qid
        foreign key (completion_id) references qbms.question (question_id)
            on update cascade on delete cascade
);

create table if not exists qbms.judgment_question
(
    judgment_id      int          not null comment '判断题题号'
        primary key,
    judgment_content varchar(255) not null comment '判断题内容',
    judgment_answer  tinyint      not null comment '判断题答案，0为错，1为对',
    constraint Judgment_Qid
        foreign key (judgment_id) references qbms.question (question_id)
            on update cascade on delete cascade
);

create table if not exists qbms.short_answer_question
(
    shortAnswer_id      int          not null comment '简答题题号'
        primary key,
    shortAnswer_content varchar(255) not null comment '大题题干内容',
    constraint shortAnswer_Qid
        foreign key (shortAnswer_id) references qbms.question (question_id)
            on update cascade on delete cascade
)
    charset = utf8;

create table if not exists qbms.sub_question
(
    `Sub-question_id`      int          not null,
    shortAnswer_id         int          not null,
    `Sub-question_No`      int          not null,
    `Sub-question_content` varchar(255) not null,
    `Sub-question_answer`  varchar(255) not null,
    `Sub-question_score`   int          not null,
    primary key (`Sub-question_id`, shortAnswer_id),
    constraint `Sub-question_SAid`
        foreign key (shortAnswer_id) references qbms.shortanswer_question (shortAnswer_id)
            on update cascade on delete cascade
)
    charset = utf8;

create table if not exists qbms.teacher
(
    teacher_id    int          not null comment '教师号'
        primary key,
    teacher_name  varchar(20)  not null comment '教师名',
    teacher_psw   varchar(20)  not null comment '教师登录密码',
    teacher_photo varchar(255) null comment '教师照片'
);

create table if not exists qbms.tc
(
    course  int not null comment '课程号',
    teacher int not null comment '教师号',
    primary key (course, teacher),
    constraint Tcourse_Course
        foreign key (course) references qbms.course (course_id)
            on update cascade on delete cascade,
    constraint Tcourse_Teacher
        foreign key (course) references qbms.teacher (teacher_id)
            on update cascade on delete cascade
);


