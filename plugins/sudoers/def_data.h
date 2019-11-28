#define I_SYSLOG                0
#define def_syslog              (sudo_defs_table[I_SYSLOG].sd_un.ival)
#define I_SYSLOG_GOODPRI        1
#define def_syslog_goodpri      (sudo_defs_table[I_SYSLOG_GOODPRI].sd_un.ival)
#define I_SYSLOG_BADPRI         2
#define def_syslog_badpri       (sudo_defs_table[I_SYSLOG_BADPRI].sd_un.ival)
#define I_LONG_OTP_PROMPT       3
#define def_long_otp_prompt     (sudo_defs_table[I_LONG_OTP_PROMPT].sd_un.flag)
#define I_IGNORE_DOT            4
#define def_ignore_dot          (sudo_defs_table[I_IGNORE_DOT].sd_un.flag)
#define I_MAIL_ALWAYS           5
#define def_mail_always         (sudo_defs_table[I_MAIL_ALWAYS].sd_un.flag)
#define I_MAIL_BADPASS          6
#define def_mail_badpass        (sudo_defs_table[I_MAIL_BADPASS].sd_un.flag)
#define I_MAIL_NO_USER          7
#define def_mail_no_user        (sudo_defs_table[I_MAIL_NO_USER].sd_un.flag)
#define I_MAIL_NO_HOST          8
#define def_mail_no_host        (sudo_defs_table[I_MAIL_NO_HOST].sd_un.flag)
#define I_MAIL_NO_PERMS         9
#define def_mail_no_perms       (sudo_defs_table[I_MAIL_NO_PERMS].sd_un.flag)
#define I_MAIL_ALL_CMNDS        10
#define def_mail_all_cmnds      (sudo_defs_table[I_MAIL_ALL_CMNDS].sd_un.flag)
#define I_TTY_TICKETS           11
#define def_tty_tickets         (sudo_defs_table[I_TTY_TICKETS].sd_un.flag)
#define I_LECTURE               12
#define def_lecture             (sudo_defs_table[I_LECTURE].sd_un.tuple)
#define I_LECTURE_FILE          13
#define def_lecture_file        (sudo_defs_table[I_LECTURE_FILE].sd_un.str)
#define I_AUTHENTICATE          14
#define def_authenticate        (sudo_defs_table[I_AUTHENTICATE].sd_un.flag)
#define I_ROOT_SUDO             15
#define def_root_sudo           (sudo_defs_table[I_ROOT_SUDO].sd_un.flag)
#define I_LOG_HOST              16
#define def_log_host            (sudo_defs_table[I_LOG_HOST].sd_un.flag)
#define I_LOG_YEAR              17
#define def_log_year            (sudo_defs_table[I_LOG_YEAR].sd_un.flag)
#define I_SHELL_NOARGS          18
#define def_shell_noargs        (sudo_defs_table[I_SHELL_NOARGS].sd_un.flag)
#define I_SET_HOME              19
#define def_set_home            (sudo_defs_table[I_SET_HOME].sd_un.flag)
#define I_ALWAYS_SET_HOME       20
#define def_always_set_home     (sudo_defs_table[I_ALWAYS_SET_HOME].sd_un.flag)
#define I_PATH_INFO             21
#define def_path_info           (sudo_defs_table[I_PATH_INFO].sd_un.flag)
#define I_FQDN                  22
#define def_fqdn                (sudo_defs_table[I_FQDN].sd_un.flag)
#define I_INSULTS               23
#define def_insults             (sudo_defs_table[I_INSULTS].sd_un.flag)
#define I_REQUIRETTY            24
#define def_requiretty          (sudo_defs_table[I_REQUIRETTY].sd_un.flag)
#define I_ENV_EDITOR            25
#define def_env_editor          (sudo_defs_table[I_ENV_EDITOR].sd_un.flag)
#define I_ROOTPW                26
#define def_rootpw              (sudo_defs_table[I_ROOTPW].sd_un.flag)
#define I_RUNASPW               27
#define def_runaspw             (sudo_defs_table[I_RUNASPW].sd_un.flag)
#define I_TARGETPW              28
#define def_targetpw            (sudo_defs_table[I_TARGETPW].sd_un.flag)
#define I_USE_LOGINCLASS        29
#define def_use_loginclass      (sudo_defs_table[I_USE_LOGINCLASS].sd_un.flag)
#define I_SET_LOGNAME           30
#define def_set_logname         (sudo_defs_table[I_SET_LOGNAME].sd_un.flag)
#define I_STAY_SETUID           31
#define def_stay_setuid         (sudo_defs_table[I_STAY_SETUID].sd_un.flag)
#define I_PRESERVE_GROUPS       32
#define def_preserve_groups     (sudo_defs_table[I_PRESERVE_GROUPS].sd_un.flag)
#define I_LOGLINELEN            33
#define def_loglinelen          (sudo_defs_table[I_LOGLINELEN].sd_un.uival)
#define I_TIMESTAMP_TIMEOUT     34
#define def_timestamp_timeout   (sudo_defs_table[I_TIMESTAMP_TIMEOUT].sd_un.tspec)
#define I_PASSWD_TIMEOUT        35
#define def_passwd_timeout      (sudo_defs_table[I_PASSWD_TIMEOUT].sd_un.tspec)
#define I_PASSWD_TRIES          36
#define def_passwd_tries        (sudo_defs_table[I_PASSWD_TRIES].sd_un.uival)
#define I_UMASK                 37
#define def_umask               (sudo_defs_table[I_UMASK].sd_un.mode)
#define I_LOGFILE               38
#define def_logfile             (sudo_defs_table[I_LOGFILE].sd_un.str)
#define I_MAILERPATH            39
#define def_mailerpath          (sudo_defs_table[I_MAILERPATH].sd_un.str)
#define I_MAILERFLAGS           40
#define def_mailerflags         (sudo_defs_table[I_MAILERFLAGS].sd_un.str)
#define I_MAILTO                41
#define def_mailto              (sudo_defs_table[I_MAILTO].sd_un.str)
#define I_MAILFROM              42
#define def_mailfrom            (sudo_defs_table[I_MAILFROM].sd_un.str)
#define I_MAILSUB               43
#define def_mailsub             (sudo_defs_table[I_MAILSUB].sd_un.str)
#define I_BADPASS_MESSAGE       44
#define def_badpass_message     (sudo_defs_table[I_BADPASS_MESSAGE].sd_un.str)
#define I_LECTURE_STATUS_DIR    45
#define def_lecture_status_dir  (sudo_defs_table[I_LECTURE_STATUS_DIR].sd_un.str)
#define I_TIMESTAMPDIR          46
#define def_timestampdir        (sudo_defs_table[I_TIMESTAMPDIR].sd_un.str)
#define I_TIMESTAMPOWNER        47
#define def_timestampowner      (sudo_defs_table[I_TIMESTAMPOWNER].sd_un.str)
#define I_EXEMPT_GROUP          48
#define def_exempt_group        (sudo_defs_table[I_EXEMPT_GROUP].sd_un.str)
#define I_PASSPROMPT            49
#define def_passprompt          (sudo_defs_table[I_PASSPROMPT].sd_un.str)
#define I_PASSPROMPT_OVERRIDE   50
#define def_passprompt_override (sudo_defs_table[I_PASSPROMPT_OVERRIDE].sd_un.flag)
#define I_RUNAS_DEFAULT         51
#define def_runas_default       (sudo_defs_table[I_RUNAS_DEFAULT].sd_un.str)
#define I_SECURE_PATH           52
#define def_secure_path         (sudo_defs_table[I_SECURE_PATH].sd_un.str)
#define I_EDITOR                53
#define def_editor              (sudo_defs_table[I_EDITOR].sd_un.str)
#define I_LISTPW                54
#define def_listpw              (sudo_defs_table[I_LISTPW].sd_un.tuple)
#define I_VERIFYPW              55
#define def_verifypw            (sudo_defs_table[I_VERIFYPW].sd_un.tuple)
#define I_NOEXEC                56
#define def_noexec              (sudo_defs_table[I_NOEXEC].sd_un.flag)
#define I_IGNORE_LOCAL_SUDOERS  57
#define def_ignore_local_sudoers (sudo_defs_table[I_IGNORE_LOCAL_SUDOERS].sd_un.flag)
#define I_CLOSEFROM             58
#define def_closefrom           (sudo_defs_table[I_CLOSEFROM].sd_un.ival)
#define I_CLOSEFROM_OVERRIDE    59
#define def_closefrom_override  (sudo_defs_table[I_CLOSEFROM_OVERRIDE].sd_un.flag)
#define I_SETENV                60
#define def_setenv              (sudo_defs_table[I_SETENV].sd_un.flag)
#define I_ENV_RESET             61
#define def_env_reset           (sudo_defs_table[I_ENV_RESET].sd_un.flag)
#define I_ENV_CHECK             62
#define def_env_check           (sudo_defs_table[I_ENV_CHECK].sd_un.list)
#define I_ENV_DELETE            63
#define def_env_delete          (sudo_defs_table[I_ENV_DELETE].sd_un.list)
#define I_ENV_KEEP              64
#define def_env_keep            (sudo_defs_table[I_ENV_KEEP].sd_un.list)
#define I_ROLE                  65
#define def_role                (sudo_defs_table[I_ROLE].sd_un.str)
#define I_TYPE                  66
#define def_type                (sudo_defs_table[I_TYPE].sd_un.str)
#define I_ENV_FILE              67
#define def_env_file            (sudo_defs_table[I_ENV_FILE].sd_un.str)
#define I_RESTRICTED_ENV_FILE   68
#define def_restricted_env_file (sudo_defs_table[I_RESTRICTED_ENV_FILE].sd_un.str)
#define I_SUDOERS_LOCALE        69
#define def_sudoers_locale      (sudo_defs_table[I_SUDOERS_LOCALE].sd_un.str)
#define I_VISIBLEPW             70
#define def_visiblepw           (sudo_defs_table[I_VISIBLEPW].sd_un.flag)
#define I_PWFEEDBACK            71
#define def_pwfeedback          (sudo_defs_table[I_PWFEEDBACK].sd_un.flag)
#define I_FAST_GLOB             72
#define def_fast_glob           (sudo_defs_table[I_FAST_GLOB].sd_un.flag)
#define I_UMASK_OVERRIDE        73
#define def_umask_override      (sudo_defs_table[I_UMASK_OVERRIDE].sd_un.flag)
#define I_LOG_INPUT             74
#define def_log_input           (sudo_defs_table[I_LOG_INPUT].sd_un.flag)
#define I_LOG_OUTPUT            75
#define def_log_output          (sudo_defs_table[I_LOG_OUTPUT].sd_un.flag)
#define I_COMPRESS_IO           76
#define def_compress_io         (sudo_defs_table[I_COMPRESS_IO].sd_un.flag)
#define I_USE_PTY               77
#define def_use_pty             (sudo_defs_table[I_USE_PTY].sd_un.flag)
#define I_GROUP_PLUGIN          78
#define def_group_plugin        (sudo_defs_table[I_GROUP_PLUGIN].sd_un.str)
#define I_IOLOG_DIR             79
#define def_iolog_dir           (sudo_defs_table[I_IOLOG_DIR].sd_un.str)
#define I_IOLOG_FILE            80
#define def_iolog_file          (sudo_defs_table[I_IOLOG_FILE].sd_un.str)
#define I_SET_UTMP              81
#define def_set_utmp            (sudo_defs_table[I_SET_UTMP].sd_un.flag)
#define I_UTMP_RUNAS            82
#define def_utmp_runas          (sudo_defs_table[I_UTMP_RUNAS].sd_un.flag)
#define I_PRIVS                 83
#define def_privs               (sudo_defs_table[I_PRIVS].sd_un.str)
#define I_LIMITPRIVS            84
#define def_limitprivs          (sudo_defs_table[I_LIMITPRIVS].sd_un.str)
#define I_EXEC_BACKGROUND       85
#define def_exec_background     (sudo_defs_table[I_EXEC_BACKGROUND].sd_un.flag)
#define I_PAM_SERVICE           86
#define def_pam_service         (sudo_defs_table[I_PAM_SERVICE].sd_un.str)
#define I_PAM_LOGIN_SERVICE     87
#define def_pam_login_service   (sudo_defs_table[I_PAM_LOGIN_SERVICE].sd_un.str)
#define I_PAM_SETCRED           88
#define def_pam_setcred         (sudo_defs_table[I_PAM_SETCRED].sd_un.flag)
#define I_PAM_SESSION           89
#define def_pam_session         (sudo_defs_table[I_PAM_SESSION].sd_un.flag)
#define I_PAM_ACCT_MGMT         90
#define def_pam_acct_mgmt       (sudo_defs_table[I_PAM_ACCT_MGMT].sd_un.flag)
#define I_MAXSEQ                91
#define def_maxseq              (sudo_defs_table[I_MAXSEQ].sd_un.str)
#define I_USE_NETGROUPS         92
#define def_use_netgroups       (sudo_defs_table[I_USE_NETGROUPS].sd_un.flag)
#define I_SUDOEDIT_CHECKDIR     93
#define def_sudoedit_checkdir   (sudo_defs_table[I_SUDOEDIT_CHECKDIR].sd_un.flag)
#define I_SUDOEDIT_FOLLOW       94
#define def_sudoedit_follow     (sudo_defs_table[I_SUDOEDIT_FOLLOW].sd_un.flag)
#define I_ALWAYS_QUERY_GROUP_PLUGIN 95
#define def_always_query_group_plugin (sudo_defs_table[I_ALWAYS_QUERY_GROUP_PLUGIN].sd_un.flag)
#define I_NETGROUP_TUPLE        96
#define def_netgroup_tuple      (sudo_defs_table[I_NETGROUP_TUPLE].sd_un.flag)
#define I_IGNORE_AUDIT_ERRORS   97
#define def_ignore_audit_errors (sudo_defs_table[I_IGNORE_AUDIT_ERRORS].sd_un.flag)
#define I_IGNORE_IOLOG_ERRORS   98
#define def_ignore_iolog_errors (sudo_defs_table[I_IGNORE_IOLOG_ERRORS].sd_un.flag)
#define I_IGNORE_LOGFILE_ERRORS 99
#define def_ignore_logfile_errors (sudo_defs_table[I_IGNORE_LOGFILE_ERRORS].sd_un.flag)
#define I_MATCH_GROUP_BY_GID    100
#define def_match_group_by_gid  (sudo_defs_table[I_MATCH_GROUP_BY_GID].sd_un.flag)
#define I_SYSLOG_MAXLEN         101
#define def_syslog_maxlen       (sudo_defs_table[I_SYSLOG_MAXLEN].sd_un.uival)
#define I_IOLOG_USER            102
#define def_iolog_user          (sudo_defs_table[I_IOLOG_USER].sd_un.str)
#define I_IOLOG_GROUP           103
#define def_iolog_group         (sudo_defs_table[I_IOLOG_GROUP].sd_un.str)
#define I_IOLOG_MODE            104
#define def_iolog_mode          (sudo_defs_table[I_IOLOG_MODE].sd_un.mode)
#define I_FDEXEC                105
#define def_fdexec              (sudo_defs_table[I_FDEXEC].sd_un.tuple)
#define I_IGNORE_UNKNOWN_DEFAULTS 106
#define def_ignore_unknown_defaults (sudo_defs_table[I_IGNORE_UNKNOWN_DEFAULTS].sd_un.flag)
#define I_COMMAND_TIMEOUT       107
#define def_command_timeout     (sudo_defs_table[I_COMMAND_TIMEOUT].sd_un.ival)
#define I_USER_COMMAND_TIMEOUTS 108
#define def_user_command_timeouts (sudo_defs_table[I_USER_COMMAND_TIMEOUTS].sd_un.flag)
#define I_IOLOG_FLUSH           109
#define def_iolog_flush         (sudo_defs_table[I_IOLOG_FLUSH].sd_un.flag)
#define I_SYSLOG_PID            110
#define def_syslog_pid          (sudo_defs_table[I_SYSLOG_PID].sd_un.flag)
#define I_TIMESTAMP_TYPE        111
#define def_timestamp_type      (sudo_defs_table[I_TIMESTAMP_TYPE].sd_un.tuple)
#define I_AUTHFAIL_MESSAGE      112
#define def_authfail_message    (sudo_defs_table[I_AUTHFAIL_MESSAGE].sd_un.str)
#define I_CASE_INSENSITIVE_USER 113
#define def_case_insensitive_user (sudo_defs_table[I_CASE_INSENSITIVE_USER].sd_un.flag)
#define I_CASE_INSENSITIVE_GROUP 114
#define def_case_insensitive_group (sudo_defs_table[I_CASE_INSENSITIVE_GROUP].sd_un.flag)
#define I_LOG_ALLOWED           115
#define def_log_allowed         (sudo_defs_table[I_LOG_ALLOWED].sd_un.flag)
#define I_LOG_DENIED            116
#define def_log_denied          (sudo_defs_table[I_LOG_DENIED].sd_un.flag)
#define I_LOG_SERVERS           117
#define def_log_servers         (sudo_defs_table[I_LOG_SERVERS].sd_un.list)
#define I_LOG_SERVER_TIMEOUT    118
#define def_log_server_timeout  (sudo_defs_table[I_LOG_SERVER_TIMEOUT].sd_un.ival)
#define I_LOG_SERVER_CABUNDLE   119
#define def_log_server_cabundle (sudo_defs_table[I_LOG_SERVER_CABUNDLE].sd_un.str)
#define I_LOG_SERVER_PEER_CERT  120
#define def_log_server_peer_cert (sudo_defs_table[I_LOG_SERVER_PEER_CERT].sd_un.str)
#define I_LOG_SERVER_PEER_KEY   121
#define def_log_server_peer_key (sudo_defs_table[I_LOG_SERVER_PEER_KEY].sd_un.str)

enum def_tuple {
	never,
	once,
	always,
	any,
	all,
	digest_only,
	global,
	ppid,
	tty,
	kernel
};
